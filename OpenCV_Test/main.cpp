#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main()
{
    //Step 1. �̹����� �ҷ��� 
    Mat img = cv::imread("C:/Users/JYPLab/Desktop/1234.jpg", IMREAD_GRAYSCALE); // �̹����� ����� MAT Class�� �ҷ����� �Լ�.  cv:: imread(�̹��� ���)
    Mat img_edge;

    //Step 2. Canny �˰����� �̿��Ͽ� ��輱�� �����س�. 
    Canny(img, img_edge, 100, 150); // THRESHOLD2 ���� ������ ���� �ʿ䰡 ����. �ʹ� ������ �������� �������� ���� ����

    //Step 3. UI�� ǥ������ 
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE); // Create window
    imshow("First OpenCV Application", img_edge); // �̹����� ��ܿ� ��� �� �Ű������� ���� ����� �ߴ����� �޶���. 
    imshow("Second OpenCV Application", img); // �̹����� ��ܿ� ��� �� �Ű������� ���� ����� �ߴ����� �޶���. 
    moveWindow("First OpenCV Application", 0, 45);
    waitKey(0); // Terminate when you press 0 
    destroyAllWindows();
    // Q. ���� ���·� ������ �� � FLAG�� ������ ���� ������? 
    return 0;
}