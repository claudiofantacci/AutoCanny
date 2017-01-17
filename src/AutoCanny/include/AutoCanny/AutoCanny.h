#ifndef AUTOCANNY_HPP
#define AUTOCANNY_HPP

#include <opencv2/core/core.hpp>


namespace autocanny
{

/**
 * @brief Finds edges in an image using the Canny algorithm.
 *
 * The function finds edges in the input image and marks them in the output map edges using the Canny algorithm.
 * See <http://en.wikipedia.org/wiki/Canny_edge_detector>.
 * @param src 8-bit single channel (CV_8UC1) or color (CV_8UC3) input image
 * @param dst output edge map; single channels 8-bit image (CV_8UC1), which has the same size as src
 * @param sigma standard deviation of the Gaussian filter; the size of the Gaussian filter is automatically chosen based on sigma; default is sqrt(2)
 * @param percent_nonedge_pixels percentage of rejected edge pixels in the range [0.0, 1.0]; degault is 0.8
 * @param highlow_threshold_ratio lower threshold is evaluated as `high * highlow_threshold_ratio`, the ratio is in the range [0.0, 1.0]; higher threshold `high` is evaluated automatically; default is 0.4
*/
void AutoCanny(const cv::Mat & src, cv::Mat & dst,
               const double sigma = 1.4142, const double percent_nonedge_pixels = 0.8, const double highlow_threshold_ratio = 0.4);


/**
 * @brief Finds edges in an image using the Canny algorithm. The value of each pixel corresponds to the edge direction.
 *
 * The function finds edges in the input image and marks them in the output map edges using the Canny algorithm.
 * See <http://en.wikipedia.org/wiki/Canny_edge_detector>.
 * Furthermore, each pixel value of a detected edge equals the direction of the edge itself. Direction is expressed in radians in the range [0, 2\f$\pi\f$].
 * @param src 8-bit single channel (CV_8UC1) or color (CV_8UC3) input image
 * @param dst output directed edge map; single channels 16-bit float image (CV_16FC1), which has the same size as src; direction expressed in radians
 * @param sigma standard deviation of the Gaussian filter; the size of the Gaussian filter is automatically chosen based on sigma; default is sqrt(2)
 * @param percent_nonedge_pixels percentage of rejected edge pixels in the range [0.0, 1.0]; degault is 0.8
 * @param highlow_threshold_ratio lower threshold is evaluated as `high * highlow_threshold_ratio`, the ratio is in the range [0.0, 1.0]; higher threshold `high` is evaluated automatically; default is 0.4
*/
void AutoDirCanny(const cv::Mat & src, cv::Mat & dst,
                  const double sigma = 1.4142, const double percent_nonedge_pixels = 0.8, const double highlow_threshold_ratio = 0.4);

} // namespace autocanny

#endif /* AUTOCANNY_HPP */
