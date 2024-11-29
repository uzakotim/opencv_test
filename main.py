import cv2

# Open the default camera (index 0)
camera = cv2.VideoCapture(0)

# Check if the camera is opened successfully
if not camera.isOpened():
    print("Error: Could not open camera.")
    exit()

print("Press 's' to save a frame. Press 'q' to quit.")

frame_count = 0  # To keep track of saved frames

while True:
    # Read a frame from the camera
    ret, frame = camera.read()
    if not ret:
        print("Failed to grab a frame.")
        break

    # Display the frame in a window
    # cv2.imshow("Camera Feed", frame)

    # Wait for a key press
    # key = cv2.waitKey(1) & 0xFF  # Mask for 64-bit systems

    # if key == ord('q'):  # Quit if 'q' is pressed
        # print("Quitting...")
        # break
    # elif key == ord('s'):  # Save frame if 's' is pressed
        # frame_count += 1
        # filename = f"frame_{frame_count}.png"
        # cv2.imwrite(filename, frame)
        # print(f"Frame saved as {filename}")

# Release the camera and close all OpenCV windows
camera.release()
cv2.destroyAllWindows()