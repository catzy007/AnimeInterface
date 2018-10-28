#include <gtk/gtk.h>
#include "mybatmax.h"

//set width and height of bgimage for size request
//default MySignal is 0
//if your bgimage is gif, change IsAnimation to 1. default is 0
MyWindow window1 = {.MyWidth=720, .MyHeight=480, .MySignal=0, .IsAnimation=1};

#define MyMin 40 //change this to set minimum battery percentage
#define MyMax 90 //change this to set maximum battery percentage

//some widget
GtkWidget *popup;
GtkWidget *g_TextSbj;
GtkWidget *g_TextMsg;
GtkWidget *img;
GtkWidget *image;
GtkWidget *imgOP;
GtkWidget *imageOP;
GtkWidget *ContFixed;
GtkWidget *ContBox;

//some function
static gboolean MyFunction (gpointer user_data);
void myhide();
static gboolean imgOPHide();

int main(int argc, char *argv[]){
//initialize gtk
    gtk_init(&argc, &argv);
    
//initialize some widget
	//initialize main window
	popup = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//initialize container
	ContFixed = gtk_fixed_new();
	ContBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	//initialize image and animation
	imageOP = gtk_image_new_from_file("src1.gif");
	imgOP = gtk_image_new_from_animation(gtk_image_get_animation(GTK_IMAGE(imageOP)));
	image = gtk_image_new_from_file("src2.gif");
	img = gtk_image_new_from_animation(gtk_image_get_animation(GTK_IMAGE(image)));
	//initialize text and set some text markup
	g_TextMsg = gtk_label_new("");
	g_TextSbj = gtk_label_new("");
	//for more text layouting https://developer.gnome.org/pango/stable/PangoMarkupFormat.html
	gtk_label_set_markup (GTK_LABEL (g_TextSbj), "<span bgcolor=\"#FFFFFF\" bgalpha=\"70%\" size=\"22000\">Subject:</span>");
	gtk_label_set_markup (GTK_LABEL (g_TextMsg), "<span bgcolor=\"#FFFFFF\" bgalpha=\"70%\" size=\"22000\" weight=\"bold\">Hello!</span>");

//set additional parameter for main window and size request
	gtk_window_set_type_hint(GTK_WINDOW(popup),GDK_WINDOW_TYPE_HINT_DOCK);
	gtk_window_set_position(GTK_WINDOW(popup),GTK_WIN_POS_CENTER);
	gtk_widget_set_size_request(ContBox,window1.MyWidth,window1.MyHeight);  
	
//filling main window, container, content, etc
	gtk_container_add(GTK_CONTAINER(popup), ContFixed);
	gtk_fixed_put (GTK_FIXED(ContFixed), window1.IsAnimation?img:image, 0, 0);
	gtk_fixed_put (GTK_FIXED(ContFixed), window1.IsAnimation?imgOP:imageOP, 0, 0);
	gtk_fixed_put (GTK_FIXED(ContFixed), ContBox, 0, 0);
	//set horizontal alignment of text
	//gtk_label_set_xalign(GTK_LABEL(g_TextSbj),1);
	gtk_label_set_xalign(GTK_LABEL(g_TextMsg),0.43);
	//set vertical alignment of text
	//gtk_label_set_yalign(GTK_LABEL(g_TextSbj),0.25);
	gtk_label_set_yalign(GTK_LABEL(g_TextMsg),0.6);
	//gtk_box_pack_start(GTK_BOX(ContBox), g_TextSbj, 1, 1, 0);
	gtk_box_pack_start(GTK_BOX(ContBox), g_TextMsg, 1, 1, 0);
	
//calling function every 2000ms
    g_timeout_add (2000, MyFunction, popup);
   
//some signal connect
    g_signal_connect(popup, "button_press_event", G_CALLBACK(myhide), NULL);
    g_signal_connect(popup, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_main();
    return 0;
}

//Hide main window if called
void myhide(){
	gtk_widget_hide(popup);
	window1.MySignal=0;
}

static gboolean imgOPHide(){
	gtk_widget_hide(imgOP);
	gtk_widget_show(g_TextMsg);
	return G_SOURCE_REMOVE;
}

//MyFancy function
static gboolean MyFunction (gpointer user_data){
	
	if(window1.MySignal==0){
		if(MyBatState() && MyBatPrecMax(MyMax)){
			gtk_label_set_markup (GTK_LABEL (g_TextMsg), 
			"<span size=\"22000\">Subject:\n</span><span size=\"22000\" weight=\"bold\">Unplug\nCharger\nNow!</span>");
			gtk_widget_show_all(popup);
			gtk_widget_hide(g_TextMsg);
			g_timeout_add (1400, imgOPHide, NULL);
			window1.MySignal=1;
		}else if(MyBatState()==0 && MyBatPrecMin(MyMin)){
			gtk_label_set_markup (GTK_LABEL (g_TextMsg), 
			"<span size=\"22000\">Subject:\n</span><span size=\"22000\" weight=\"bold\">Plug\nCharger\nNow!</span>");
			gtk_widget_show_all(popup);
			gtk_widget_hide(g_TextMsg);
			g_timeout_add (1400, imgOPHide, NULL);
			window1.MySignal=1;
		}else if(MyBatState()==1){
			//printf("Charging\n");
		}else{
			//printf("Discharging\n");
		}
	}else{
		if(MyBatState() && MyBatPrecMax(MyMax)){
			//printf("Unplug Charger Now!\n");
		}else if(MyBatState()==0 && MyBatPrecMin(MyMin)){
			//printf("Plug Charger Now!\n");
		}else if(MyBatState()==1){
			//printf("Charging\n");
		}else{
			//printf("Discharging\n");
		}
	}
	return G_SOURCE_CONTINUE; /* or G_SOURCE_REMOVE when you want to stop */
}
