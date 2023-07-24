using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        // Create a rectangle and add it to the page. Also,
        // find size and coordinate information about this
        // new rectangle and render information in a TextBox 
        // below the rectangle.
        private StackPanel createRectExample1()
        {
            // Initialize new rectangle.
            Rect myRectangle = new Rect();

            // The Location property specifies the coordinates of the upper left-hand 
            // corner of the rectangle. Set the Location property to an X coordinate of 10 and a
            // Y coordinate of 5. 
            myRectangle.Location = new Point(10, 5);

            // Set the Size property of the rectangle with a width of 200
            // and a height of 50.
            myRectangle.Size = new Size(200, 50);

            RectangleGeometry myRectangleGeometry = new RectangleGeometry();
            myRectangleGeometry.Rect = myRectangle;

            // This path is defined by the rectangle.
            Path myPath = new Path();
            myPath.Fill = Brushes.LemonChiffon;
            myPath.Stroke = Brushes.Black;
            myPath.StrokeThickness = 1;
            myPath.Data = myRectangleGeometry;

            //////////// Create string of rectangle property information /////////////
            // This string will contain all the size and coordinate property
            // information about the rectangle.
            /////////////////////////////////////////////////////////////////////////
            string rectInfo = "Rectangle Property Information: ";

            // Bottom property gets the y-axis value of the bottom of the rectangle. 
            // For this rectangle the value is 55.
            rectInfo = rectInfo + "Bottom: " + myRectangle.Bottom;

            // BottomLeft property gets the coordinates of the bottom left corner of the rectangle. 
            // For this rectangle the value is 10,55.
            rectInfo = rectInfo + "| BottomLeft: " + myRectangle.BottomLeft;

            // BottomRight property gets the coordinates of the bottom right corner of the rectangle. 
            // For this rectangle the value is 210,55.
            rectInfo = rectInfo + "| BottomRight: " + myRectangle.BottomRight;

            // Height property gets or sets the height of the rectangle. 
            // For this rectangle the value is 50.
            rectInfo = rectInfo + "| Height: " + myRectangle.Height;

            // Width property gets or sets the width of the rectangle. 
            // For this rectangle the value is 200.
            rectInfo = rectInfo + "| Width: " + myRectangle.Width;

            // Left property gets the x-axis position of the left side of the rectangle which is 
            // equivalent to getting the rectangle's X property. 
            // For this rectangle the value is 10.
            rectInfo = rectInfo + "| Left: " + myRectangle.Left;

            // Location property gets or sets the position of the rectangle's top-left corner.
            // For this rectangle the value is 10,5.
            rectInfo = rectInfo + "| Location: " + myRectangle.Location;

            // Right property gets the x-axis value of the right side of the rectangle. 
            // For this rectangle the value is 210.
            rectInfo = rectInfo + "| Right: " + myRectangle.Right;

            // Size property gets or sets the width and height of the rectangle.  
            // For this rectangle the value is 200,50.
            rectInfo = rectInfo + "| Size: " + myRectangle.Size;

            // Top property gets the y-axis position of the top of the rectangle which is 
            // equivalent to getting the rectangle's Y property.
            // For this rectangle the value is 5.
            rectInfo = rectInfo + "| Top: " + myRectangle.Top;

            // TopLeft property gets the position of the top-left corner of the rectangle, which 
            // is equivalent to (X, Y).   
            // For this rectangle the value is 10,5.
            rectInfo = rectInfo + "| TopLeft: " + myRectangle.TopLeft;

            // TopRight property gets the position of the top-left corner of the rectangle, which 
            // is equivalent to (X + Width, Y).   
            // For this rectangle the value is 210,5.
            rectInfo = rectInfo + "| TopRight: " + myRectangle.TopRight;

            // X property gets or sets the location of the rectangle's left side.  
            // For this rectangle the value is 10.
            rectInfo = rectInfo + "| X: " + myRectangle.X;

            // Y property gets or sets the location of the rectangle's top side.  
            // For this rectangle the value is 5.
            rectInfo = rectInfo + "| Y: " + myRectangle.Y;

            //////// End of creating string containing rectangle property information ////////

            // This StackPanel will contain the rectangle and TextBlock.
            StackPanel parentPanel = new StackPanel();

            // Add the rectangle path to the StackPanel. This will display the rectangle.
            parentPanel.Children.Add(myPath);

            // Add a TextBlock to display the rectangle's size and coordinate information.
            TextBlock myTextBlock = new TextBlock();
            myTextBlock.Text = rectInfo;
            parentPanel.Children.Add(myTextBlock);

            // Return the parent container to be displayed to the screen.
            return parentPanel;
        }
    }
}
