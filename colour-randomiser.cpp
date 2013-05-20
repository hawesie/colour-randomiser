#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/unordered_map.hpp>

using namespace cv;
using namespace std;
using namespace boost::random;


///random number generator
mt19937 generator;

uniform_int_distribution<> dist(0, 255);

typedef boost::unordered_map<int, int> int_map;
int_map colourMap;


int randomReplace(int _in)
{

    int_map::iterator i = colourMap.find(_in);
    if (i == colourMap.end())
    {
        i = colourMap.insert(i, int_map::value_type(_in,dist(generator)));
    }

    // cout << _in << endl;
    // return _in;
    return i->second;
}

int main( int argc, char **argv )
{
    generator.seed(static_cast<unsigned int>(std::time(0)));

    /// Read image given by user
    Mat image = imread( argv[1] );
    Mat new_image = Mat::zeros( image.size(), image.type() );


    /// Do the operation new_image(i,j) = alpha*image(i,j) + beta
    for ( int y = 0; y < image.rows; y++ )
    {
        for ( int x = 0; x < image.cols; x++ )
        {
            for ( int c = 0; c < 3; c++ )
            {
                new_image.at<Vec3b>(y, x)[c] =  randomReplace(image.at<Vec3b>(y, x)[c]);
            }
        }
    }

    /// Create Windows
    namedWindow("Original Image", 1);
    namedWindow("New Image", 1);

    /// Show stuff
    imshow("Original Image", image);
    imshow("New Image", new_image);

    /// Wait until user press some key
    waitKey();
    return 0;
}