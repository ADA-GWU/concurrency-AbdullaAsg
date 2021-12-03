#include <iostream>
#include<thread>
#include<chrono>
#include<string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

void f(cv::Mat img, int squareSize)
{
    int avrgOfSquare[3];
    int maxRow = img.rows;
    int maxColm = img.cols;
    int colmsRemaining = 0;
    int rowsRemaining = 0;
    namedWindow("Display Image", WINDOW_NORMAL);
    resizeWindow("Display Image", 600, 600);
    imshow("Display Image", img);
    for (int rowItr = squareSize; rowItr < maxRow; rowItr += 2 * squareSize)
    {
        for (int colmItr = squareSize; colmItr < maxColm; colmItr += 2 * squareSize)
        {
            int count = 0;
            int sum[3] = { 0 };
            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        sum[k] += img.at<Vec3b>(i, j)[k];
                    count++;
                }
            }
            avrgOfSquare[0] = sum[0] / count;
            avrgOfSquare[1] = sum[1] / count;
            avrgOfSquare[2] = sum[2] / count;

            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        img.at<Vec3b>(i, j)[k] = avrgOfSquare[k];
                }
            }
            namedWindow("Display Image", WINDOW_NORMAL);
            resizeWindow("Display Image", 600, 600);
            imshow("Display Image", img);
            waitKey(1);
            colmsRemaining = colmItr;
        }
        int sumOfRemain[3] = { 0 };
        int countOfRemain = 0;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {
                for (int k = 0; k < 3; k++)
                    sumOfRemain[k] += img.at<Vec3b>(i, j)[k];
                countOfRemain++;
            }
        }
        int avrgOfRemain[3];
        avrgOfRemain[0] = sumOfRemain[0] / countOfRemain;
        avrgOfRemain[1] = sumOfRemain[1] / countOfRemain;
        avrgOfRemain[2] = sumOfRemain[2] / countOfRemain;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {
                for (int k = 0; k < 3; k++)
                    img.at<Vec3b>(i, j)[k] = avrgOfRemain[k];
            }

        }
        rowsRemaining = rowItr;

    }

    for (int rowItr = rowsRemaining + 1; rowItr < maxRow; rowItr++)
    {
        for (int colmItr = squareSize; colmItr < maxColm; colmItr += 2 * squareSize)
        {
            int count = 0;
            int sum[3] = { 0 };
            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        sum[k] += img.at<Vec3b>(i, j)[k];
                    count++;
                }
            }
            avrgOfSquare[0] = sum[0] / count;
            avrgOfSquare[1] = sum[1] / count;
            avrgOfSquare[2] = sum[2] / count;

            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        img.at<Vec3b>(i, j)[k] = avrgOfSquare[k];
                }
            }

            colmsRemaining = colmItr;
        }
        int SumOfRemain[3] = { 0 };
        int countOfRemain = 0;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {

                for (int k = 0; k < 3; k++)
                    SumOfRemain[k] += img.at<Vec3b>(i, j)[k];
                countOfRemain++;

            }

        }
        int avrgOfRemain[3];
        avrgOfRemain[0] = SumOfRemain[0] / countOfRemain;
        avrgOfRemain[1] = SumOfRemain[1] / countOfRemain;
        avrgOfRemain[2] = SumOfRemain[2] / countOfRemain;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {

                for (int k = 0; k < 3; k++)
                    img.at<Vec3b>(i, j)[k] = avrgOfRemain[k];
            }
        }
        rowsRemaining = rowItr;
    }
    namedWindow("Display Image", WINDOW_NORMAL);
    resizeWindow("Display Image", 600, 600);
    imshow("Display Image", img);
    waitKey(0);
}
void f1(cv::Mat img, int squareSize)
{
    int colmsRemaining = 0;
    int rowsRemaining = 0;
    int avrgOfSquare[3];
    int maxRow = img.rows / 2;
    int maxColmn = img.cols / 2;
    for (int rowItr = squareSize; rowItr < maxRow; rowItr += 2 * squareSize)
    {
        for (int colmnItr = squareSize; colmnItr < maxColmn; colmnItr += 2 * squareSize)
        {        
            int count = 0;
            int sum[3] = { 0 };
            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmnItr - squareSize; j < colmnItr + squareSize && j < maxColmn; j++)
                {
                    for (int k = 0; k < 3; k++)
                        sum[k] += img.at<Vec3b>(i, j)[k];
                    count++;
                }
            }

            avrgOfSquare[0] = sum[0] / count;
            avrgOfSquare[1] = sum[1] / count;
            avrgOfSquare[2] = sum[2] / count;

            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmnItr - squareSize; j < colmnItr + squareSize && j < maxColmn; j++)
                {
                    for (int k = 0; k < 3; k++)
                        img.at<Vec3b>(i, j)[k] = avrgOfSquare[k];

                }
            }
            namedWindow("Display Image", WINDOW_NORMAL);
            resizeWindow("Display Image", 600, 600);
            imshow("Display Image", img);
            waitKey(10);
            colmsRemaining = colmnItr;
        }
        int sumOfRemain[3] = { 0 };
        int countOfReamain = 0;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColmn; j++)
            {
                for (int k = 0; k < 3; k++)
                    sumOfRemain[k] += img.at<Vec3b>(i, j)[k];
                countOfReamain++;
            }
        }
        if (countOfReamain == 0) countOfReamain = 1;
        int avrgOfRemain[3];
        avrgOfRemain[0] = sumOfRemain[0] / countOfReamain;
        avrgOfRemain[1] = sumOfRemain[1] / countOfReamain;
        avrgOfRemain[2] = sumOfRemain[2] / countOfReamain;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColmn; j++)
            {
                for (int k = 0; k < 3; k++)
                    img.at<Vec3b>(i, j)[k] = avrgOfRemain[k];
            }

        }
        rowsRemaining = rowItr;
    }
    for (int rowItr = rowsRemaining + 1; rowItr < maxRow; rowItr++)
    {
        for (int colmItr = squareSize; colmItr < maxColmn; colmItr += 2 * squareSize)
        {
            int count = 0;
            int sum[3] = { 0 };
            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColmn; j++)
                {
                    for (int k = 0; k < 3; k++)
                        sum[k] += img.at<Vec3b>(i, j)[k];
                    count++;
                }
            }
            avrgOfSquare[0] = sum[0] / count;
            avrgOfSquare[1] = sum[1] / count;
            avrgOfSquare[2] = sum[2] / count;

            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColmn; j++)
                {
                    for (int k = 0; k < 3; k++)
                        img.at<Vec3b>(i, j)[k] = avrgOfSquare[k];
                }
            }
            colmsRemaining = colmItr;
        }
        int sumOfRemain[3] = { 0 };
        int countOfRemain = 0;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColmn; j++)
            {
               for (int k = 0; k < 3; k++)
                    sumOfRemain[k] += img.at<Vec3b>(i, j)[k];
                countOfRemain++;
            }
        }
        if (countOfRemain == 0) countOfRemain = 1;
        int avrgOfRemain[3];
        avrgOfRemain[0] = sumOfRemain[0] / countOfRemain;
        avrgOfRemain[1] = sumOfRemain[1] / countOfRemain;
        avrgOfRemain[2] = sumOfRemain[2] / countOfRemain;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColmn; j++)
            {
                for (int k = 0; k < 3; k++)
                    img.at<Vec3b>(i, j)[k] = avrgOfRemain[k];
            }
        }
    }
    
   // cout << "f1 finished" << endl;
}
void f2(cv::Mat img, int squareSize)
{
    int colmsRemaining = 0;
    int rowsRemaining = 0;
    int avrgOfSquare[3];
    int maxRow = img.rows / 2;
    int maxColm = img.cols;

    for (int rowItr = squareSize; rowItr < maxRow; rowItr += 2 * squareSize)
    {
        for (int colmItr = maxColm / 2 + squareSize; colmItr < maxColm; colmItr += 2 * squareSize)
        {
            int count = 0;
            int sum[3] = { 0 };
            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        sum[k] += img.at<Vec3b>(i, j)[k];
                    count++;
               }
            }
            avrgOfSquare[0] = sum[0] / count;
            avrgOfSquare[1] = sum[1] / count;
            avrgOfSquare[2] = sum[2] / count;

            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        img.at<Vec3b>(i, j)[k] = avrgOfSquare[k];
                }
            }
            namedWindow("Display Image", WINDOW_NORMAL);
            resizeWindow("Display Image", 600, 600);
            imshow("Display Image", img);
            waitKey(10);
            colmsRemaining = colmItr;
        }
        int sumOfRemain[3] = { 0 };
        int countOfRemain = 0;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {
                for (int k = 0; k < 3; k++)
                    sumOfRemain[k] += img.at<Vec3b>(i, j)[k];
                countOfRemain++;
            }
        }
        if (countOfRemain == 0) countOfRemain = 1;
        int leftavrg[3];
        leftavrg[0] = sumOfRemain[0] / countOfRemain;
        leftavrg[1] = sumOfRemain[1] / countOfRemain;
        leftavrg[2] = sumOfRemain[2] / countOfRemain;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {
                for (int k = 0; k < 3; k++)
                    img.at<Vec3b>(i, j)[k] = leftavrg[k];
            }

        }
        rowsRemaining = rowItr;

    }
    for (int rowItr = rowsRemaining + 1; rowItr < maxRow; rowItr++)
    {
        for (int colmItr = maxColm / 2 + squareSize; colmItr < maxColm; colmItr += 2 * squareSize)
        {
            int count = 0;
            int sum[3] = { 0 };
            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        sum[k] += img.at<Vec3b>(i, j)[k];
                    count++;
                }
            }
            avrgOfSquare[0] = sum[0] / count;
            avrgOfSquare[1] = sum[1] / count;
            avrgOfSquare[2] = sum[2] / count;

            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        img.at<Vec3b>(i, j)[k] = avrgOfSquare[k];
                }
            }

            colmsRemaining = colmItr;
        }
        int sumOfRemain[3] = { 0 };
        int countOfRemain = 0;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {
                for (int k = 0; k < 3; k++)
                    sumOfRemain[k] += img.at<Vec3b>(i, j)[k];
                countOfRemain++;
            }
        }
        if (countOfRemain == 0) countOfRemain = 1;
        int leftavrg[3];
        leftavrg[0] = sumOfRemain[0] / countOfRemain;
        leftavrg[1] = sumOfRemain[1] / countOfRemain;
        leftavrg[2] = sumOfRemain[2] / countOfRemain;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {
                for (int k = 0; k < 3; k++)
                    img.at<Vec3b>(i, j)[k] = leftavrg[k];
            }
        }
       
    }
   // cout << "f2 finished" << endl;
    
}
void f3(cv::Mat img, int squareSize)
{
    int avrgOfSquare[3];
    int maxRow = img.rows;
    int maxColm = img.cols / 2;
    int colmsRemaining = 0;
    int rowsRemaining = 0;
    for (int rowItr = maxRow / 2 + squareSize; rowItr < maxRow; rowItr += 2 * squareSize)
    {
        for (int colmItr = squareSize; colmItr < maxColm; colmItr += 2 * squareSize)
        {
            int count = 0;
            int sum[3] = { 0 };
            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        sum[k] += img.at<Vec3b>(i, j)[k];
                    count++;
                }
            }
            avrgOfSquare[0] = sum[0] / count;
            avrgOfSquare[1] = sum[1] / count;
            avrgOfSquare[2] = sum[2] / count;

            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        img.at<Vec3b>(i, j)[k] = avrgOfSquare[k];
                }
            }
            namedWindow("Display Image", WINDOW_NORMAL);
            resizeWindow("Display Image", 600, 600);
            imshow("Display Image", img);
            waitKey(10);
            colmsRemaining = colmItr;
        }
        int sumOfRemain[3] = { 0 };
        int countOfRemain = 0;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {
                for (int k = 0; k < 3; k++)
                    sumOfRemain[k] += img.at<Vec3b>(i, j)[k];
                countOfRemain++;
            }
        }
        if (countOfRemain == 0) countOfRemain = 1;
        int avrgOfRemain[3];
        avrgOfRemain[0] = sumOfRemain[0] / countOfRemain;
        avrgOfRemain[1] = sumOfRemain[1] / countOfRemain;
        avrgOfRemain[2] = sumOfRemain[2] / countOfRemain;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {
                for (int k = 0; k < 3; k++)
                    img.at<Vec3b>(i, j)[k] = avrgOfRemain[k];
            }
        }
        rowsRemaining = rowItr;
    }
    for (int rowItr = rowsRemaining + 1; rowItr < maxRow; rowItr++)
    {
        for (int colmItr = squareSize; colmItr < maxColm; colmItr += 2 * squareSize)
        {
            int count = 0;
            int sum[3] = { 0 };
            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        sum[k] += img.at<Vec3b>(i, j)[k];
                    count++;
                }
            }
            avrgOfSquare[0] = sum[0] / count;
            avrgOfSquare[1] = sum[1] / count;
            avrgOfSquare[2] = sum[2] / count;

            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        img.at<Vec3b>(i, j)[k] = avrgOfSquare[k];
                }
            }
            colmsRemaining = colmItr;
        }
        int sumOfRemain[3] = { 0 };
        int countOfRemain = 0;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {
                for (int k = 0; k < 3; k++)
                    sumOfRemain[k] += img.at<Vec3b>(i, j)[k];
                countOfRemain++;
            }

        }
        if (countOfRemain == 0) countOfRemain = 1;
        int leftavrg[3];
        leftavrg[0] = sumOfRemain[0] / countOfRemain;
        leftavrg[1] = sumOfRemain[1] / countOfRemain;
        leftavrg[2] = sumOfRemain[2] / countOfRemain;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {

                for (int k = 0; k < 3; k++)
                    img.at<Vec3b>(i, j)[k] = leftavrg[k];
            }
        }
    }
    
   //cout << "f3 finished" << endl;
}
void f4(cv::Mat img, int squareSize)
{
    int avrgOfSquare[3];
    int maxRow = img.rows;
    int maxColm = img.cols;
    int colmsRemaining = 0;
    int rowsRemaining = 0;
    for (int rowItr = maxRow / 2 + squareSize; rowItr < maxRow; rowItr += 2 * squareSize)
    {
        for (int colmItr = maxColm / 2 + squareSize; colmItr < maxColm; colmItr += 2 * squareSize)
        {
            int count = 0;
            int sum[3] = { 0 };
            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        sum[k] += img.at<Vec3b>(i, j)[k];
                    count++;
                }

            }
            avrgOfSquare[0] = sum[0] / count;
            avrgOfSquare[1] = sum[1] / count;
            avrgOfSquare[2] = sum[2] / count;

            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        img.at<Vec3b>(i, j)[k] = avrgOfSquare[k];

                }
            }
            namedWindow("Display Image", WINDOW_NORMAL);
            resizeWindow("Display Image", 600, 600);
            imshow("Display Image", img);
            waitKey(10);
            colmsRemaining = colmItr;
        }
        int sumOfRemain[3] = { 0 };
        int countOfRemain = 0;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {
                for (int k = 0; k < 3; k++)
                    sumOfRemain[k] += img.at<Vec3b>(i, j)[k];
                countOfRemain++;
            }
        }
        if (countOfRemain == 0) countOfRemain = 1;
        int leftavrg[3];
        leftavrg[0] = sumOfRemain[0] / countOfRemain;
        leftavrg[1] = sumOfRemain[1] / countOfRemain;
        leftavrg[2] = sumOfRemain[2] / countOfRemain;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {
                for (int k = 0; k < 3; k++)
                    img.at<Vec3b>(i, j)[k] = leftavrg[k];
            }

        }
        rowsRemaining = rowItr;
    }
    for (int rowItr = rowsRemaining + 1; rowItr < maxRow; rowItr++)
    {
        for (int colmItr = maxColm / 2 + squareSize; colmItr < maxColm; colmItr += 2 * squareSize)
        {
            int count = 0;
            int sum[3] = { 0 };
            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        sum[k] += img.at<Vec3b>(i, j)[k];
                    count++;
                }
            }
            avrgOfSquare[0] = sum[0] / count;
            avrgOfSquare[1] = sum[1] / count;
            avrgOfSquare[2] = sum[2] / count;

            for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
            {
                for (int j = colmItr - squareSize; j < colmItr + squareSize && j < maxColm; j++)
                {
                    for (int k = 0; k < 3; k++)
                        img.at<Vec3b>(i, j)[k] = avrgOfSquare[k];
                }
            }

            colmsRemaining = colmItr;
        }
        int sumOfRemain[3] = { 0 };
        int countOfRemain = 0;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {

                for (int k = 0; k < 3; k++)
                    sumOfRemain[k] += img.at<Vec3b>(i, j)[k];
                countOfRemain++;
            }
        }
        if (countOfRemain == 0) countOfRemain = 1;
        int avrgOfRemaining[3];
        avrgOfRemaining[0] = sumOfRemain[0] / countOfRemain;
        avrgOfRemaining[1] = sumOfRemain[1] / countOfRemain;
        avrgOfRemaining[2] = sumOfRemain[2] / countOfRemain;
        for (int i = rowItr - squareSize; i < rowItr + squareSize && i < maxRow; i++)
        {
            for (int j = colmsRemaining + 1; j < maxColm; j++)
            {

                for (int k = 0; k < 3; k++)
                    img.at<Vec3b>(i, j)[k] = avrgOfRemaining[k];
            }
        }      
    }
    //cout << "f4 finished" << endl;
}

int main(int argc, char** argv)
{
    Mat img;
    string name;
    int n;
    string mode;
    cout << "Enter name" << endl;
    cin >> name;
    name="images/"+name;
    img = imread(name);
    if (!img.data)
    {
        printf("No image data \n");
        system("Pause");
        return 0;
    }
    int row = img.rows;
    int col = img.cols;
    cout << row << " " << col << endl;
    cout << "Enter size:";
    cin >> n;
    cout << "Enter mode (S/M):";
    cin >> mode;
    //string path = "C:/Users/TexnoUSTA/Desktop/" + name;
    if (mode == "S")
    {
        f(img, n);    
    }
    else if (mode == "M")
    {
        thread th1(f1, img, n);
        thread th2(f2, img, n);
        thread th3(f3, img, n);
        thread th4(f4, img, n);

        th1.join();
        th2.join();
        th3.join();
        th4.join();
    
        destroyAllWindows();
        namedWindow("Display Image", WINDOW_NORMAL);
        resizeWindow("Display Image", 600, 600);
        imshow("Display Image", img);
        waitKey(0);
    }
    else cout << "False mode";
   
    imwrite("images/result.jpg", img);
    return 0;
}
