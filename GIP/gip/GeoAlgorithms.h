/*##############################################################################
#    GIPPY: Geospatial Image Processing library for Python
#
#    AUTHOR: Matthew Hanson
#    EMAIL:  matt.a.hanson@gmail.com
#
#    Copyright (C) 2015 Applied Geosolutions
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
##############################################################################*/

#ifndef GIP_GEOALGORITHMS_H
#define GIP_GEOALGORITHMS_H

#include <gip/GeoImage.h>
#include <gip/GeoImages.h>
#include <gip/GeoRaster.h>
#include <gip/GeoVector.h>
#include <initializer_list>

namespace gip {
    namespace algorithms {

    std::map< std::string, std::vector<std::string> > RequiredBands = {
        {"acca", {"RED","GREEN","NIR","SWIR1","LWIR"}},
        {"truecolor", {"RED","GREEN","BLUE"}},
        {"fmask", {"BLUE", "RED", "GREEN", "NIR", "SWIR1", "SWIR2", "LWIR"}},
        // Indices
        {"ndvi", {"NIR","RED"}},
        {"evi", {"NIR","RED","BLUE"}},
        {"lswi", {"NIR","SWIR1"}},
        {"ndsi", {"SWIR1","GREEN"}},
        {"ndwi", {"GREEN","NIR"}},
        {"bi", {"BLUE","NIR"}},
        {"satvi", {"SWIR1","RED", "SWIR2"}},
        {"msavi2", {"NIR","RED"}},
        {"vari", {"RED","GREEN","BLUE"}},
        {"brgt", {"RED","GREEN","BLUE","NIR"}},
    };

    //! Create cloudmask using ACCA
    GeoImage acca(const GeoImage&, std::string, float, float, int = 5, int = 10, int = 4000, dictionary=dictionary());

    //! Stretch image into byte
    std::string browse_image(const GeoImage&, std::string, int quality=75);

    //! Create single image from multiple input images using vector file footprint
    GeoImage cookie_cutter(GeoImages images, GeoFeature feature, std::string filename, 
        float xres, float yres, bool crop=false, unsigned char interpolation=0, dictionary metadata=dictionary());

    //! Create new file with a Fmask cloud mask
    GeoImage fmask(const GeoImage&, std::string, int=3, int=5, dictionary=dictionary());

    //! Kmeans
    //GeoImage kmeans(const GeoImage&, std::string, int classes=5, int iterations=5, float threshold=1.0);

    //! Create indices in one pass: NDVI, EVI, LSWI, NDSI, BI {product, filename}
    GeoImage indices(const GeoImage&, dictionary, dictionary=dictionary());

    //! Create output based on linear combinations of input
    GeoImage linear_transform(const GeoImage&, std::string, CImg<float>);

    //! Runs the RX Detector (RXD) anamoly detection algorithm
    GeoImage rxd(const GeoImage&, std::string);

    //! Calculate spectral statistics and output to new image
    //GeoImage SpectralStatistics(const GeoImage&, std::string);

    //! Spectral Matched Filter
    //GeoImage SMF(const GeoImage& image, std::string, CImg<double>);

    //! Calculate spectral correlation
    //CImg<double> SpectralCorrelation(const GeoImage&, CImg<double> covariance=CImg<double>() );

    //! Calculate spectral covariance
    CImg<double> spectral_covariance(const GeoImage&);
    }
} // namespace gip

#endif // GIP_GEOALGORITHMS_H
