#include "ClassDesignB.h"
#include <iostream>

// These are the acceptable image types that the setter will compare against
std::string jpg = "JPG";
std::string gif = "GIF";
std::string png = "PNG";

// Class constructor with a parameter to meet each variable
ClassDesignB::ClassDesignB(std::string fileName, std::string imageType, std::string dateCreated,
	double size, std::string authorName, int imgHeight, int imgWidth,
	int apertureSize, int exposureTime, int isoValue, bool flashEnabled)
	: fileName{ fileName }, imageType{ imageType }, dateCreated{ dateCreated }, size{ size },
	authorName{ authorName }, imgHeight{ imgHeight }, imgWidth{ imgWidth }, apertureSize{ apertureSize },
	exposureTime{ exposureTime }, isoValue{ isoValue }, flashEnabled{ flashEnabled } {}

// All the getter functions for each variable
std::string ClassDesignB::getFileName() const {
	return fileName;
}
std::string ClassDesignB::getImageType() const {
	// Before setting a value, check to ensure the type is an acceptable image type
	if ((imageType.compare(jpg) == 0) || (imageType.compare(gif) == 0) || (imageType.compare(png) == 0)) {
		return imageType;
	}
	else {
		return "NOT ACCEPTABLE IMAGE TYPE INPUTED";
	}
}
std::string ClassDesignB::getDateCreated() const {
	return dateCreated;
}
double ClassDesignB::getSize() const {
	return size;
}
std::string ClassDesignB::getAuthorName() const {
	return authorName;
}
int ClassDesignB::getImageDimensions() const {
	return imgHeight * imgWidth;
}
int ClassDesignB::getImageHeight() const {
	return imgHeight;
}
int ClassDesignB::getImageWidth() const {
	return imgWidth;
}
int ClassDesignB::getApertureSize() const {
	return apertureSize;
}
int ClassDesignB::getExposureTime() const {
	return exposureTime;
}
int ClassDesignB::getISOValue() const {
	return isoValue;
}
bool ClassDesignB::getFlashEnabled() const {
	return flashEnabled;
}

// Setter functions that allow changed to each variable
void ClassDesignB::setFileName(std::string fileName) {
	fileName = fileName;
}
void ClassDesignB::setImageType(std::string imageType) {
	// Before setting a value, check to ensure the type is an acceptable image type
	if ((imageType.compare(jpg) == 0) || (imageType.compare(gif) == 0) || (imageType.compare(png) == 0)) {
		imageType = imageType;
	}
	else {
		imageType = "NOT ACCEPTABLE IMAGE TYPE INPUTED";
	}
}
void ClassDesignB::setDateCreated(std::string dateCreated) {
	dateCreated = dateCreated;
}
void ClassDesignB::setSize(double size) {
	size = size;
}
void ClassDesignB::setAuthorName(std::string authorName) {
	authorName = authorName;
}
void ClassDesignB::setImageDimensions(int imgHeight, int imgWidth) {
	imgHeight = imgHeight;
	imgWidth = imgWidth;
}
void ClassDesignB::setImageHeight(int imgHeight) {
	imgHeight = imgHeight;
}
void ClassDesignB::setImageWidth(int imgWidth) {
	imgWidth = imgWidth;
}
void ClassDesignB::setApertureSize(int apertureSize) {
	apertureSize = apertureSize;
}
void ClassDesignB::setExposureTime(int exposureTime) {
	exposureTime = exposureTime;
}
void ClassDesignB::setISOValue(int isoValue) {
	isoValue = isoValue;
}
void ClassDesignB::setFlashEnabled(bool flashEnabled) {
	flashEnabled = flashEnabled;
}

// Print function to correctly format image data
void printImageData(const ClassDesignB designB) {
	std::cout << "Data of Image File: " << designB.getFileName() << "\n" <<
		"Image Type: " << designB.getImageType() << "\n" <<
		"Date Created: " << designB.getDateCreated() << "\n" <<
		"Size: " << designB.getSize() << "\n" <<
		"Author Name: " << designB.getAuthorName() << "\n" <<
		"Image Dimensions: " << designB.getImageHeight() << " X " << designB.getImageWidth() << "\n"
		"Aperture Size: f/" << designB.getApertureSize() << "\n"
		"Exposure Time: 1/" << designB.getExposureTime() << "\n"
		"ISO Value: " << designB.getISOValue() << "\n"
		"Flash Enabled: " << designB.getFlashEnabled() << "\n" << "\n";
}