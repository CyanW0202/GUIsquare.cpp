#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
/*or append the cv:: specifier at the beginning of every OpenCV classes, functions and data structures*/

int main(int argc, char** argv){
    VideoCapture vid(2);
    if (!vid.isOpened())
    {
        cout << "Error opening video stream or file" << endl;
    }
    // Read the frames to the last frame
    while (vid.isOpened())
    {
        // Initialise frame matrix
        Mat frame = imread("");
    
        // Initialize a boolean to check if frames are there or not
        bool isSuccess = vid.read(frame);
    
        // If frames are present, show it
        if(isSuccess == true)
        {
        //display frames
        imshow("Frame", frame);
        }
    
        // If frames are not there, close it
        if (isSuccess == false)
        {
        cout << "Video camera is disconnected" << endl;
        break;
        }
        
        //wait 20 ms between successive frames and break the loop if key q is pressed
        int key = waitKey(20);
        if (key == 'q')
        {
        cout << "q key is pressed by the user. Stopping the video" << endl;
        break;
        }
    
    
    }
    return 0;
}

