#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Open the default camera (index 0)
    cv::VideoCapture camera(0);

    if (!camera.isOpened()) {
        std::cerr << "Error: Could not open the camera." << std::endl;
        return -1;
    }

    std::cout << "Press 's' to save a frame. Press 'q' to quit." << std::endl;

    cv::Mat frame;
    int frame_count = 0;  // To keep track of saved frames

    while (true) {
        // Capture a frame from the camera
        camera >> frame;

        // Check if the frame is empty
        if (frame.empty()) {
            std::cerr << "Error: Failed to grab a frame." << std::endl;
            break;
        }

        // Display the frame in a window
        cv::imshow("Camera Feed", frame);

        // Wait for a key press (1 ms delay)
        char key = (char)cv::waitKey(1);

        if (key == 'q') {  // Quit if 'q' is pressed
            std::cout << "Quitting..." << std::endl;
            break;
        } else if (key == 's') {  // Save frame if 's' is pressed
            std::string filename = "frame_" + std::to_string(++frame_count) + ".png";
            cv::imwrite(filename, frame);
            std::cout << "Frame saved as " << filename << std::endl;
        }
    }

    // Release the camera and destroy OpenCV windows
    camera.release();
    cv::destroyAllWindows();

    return 0;
}
