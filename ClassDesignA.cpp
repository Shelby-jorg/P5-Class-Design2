#include "ClassDesignA.h"
#include <string>
#include <iostream>

ClassDesignA::ClassDesignA(const std::string url)
	: userURL{ url } {}

void ClassDesignA::setPath(int authorityEnd, int schemeEnd, std::string userURL) {
	// By adding the authority end index, as well as the scheme end index, we can get the path after these parts
	path = userURL.substr((authorityEnd + schemeEnd), userURL.size());
}

void ClassDesignA::setAuthority(int authorityStart, int authorityEnd, std::string userURL) {
	authority = userURL.substr(authorityStart, authorityEnd);
}

void ClassDesignA::setScheme(int schemeEnd, std::string userURL) {
	scheme = userURL.substr(0, schemeEnd);
}

void ClassDesignA::setBrokenURL(std::string userURL, int schemeEnd) {
	// 2 is added to give the index including the //
	brokenURL = userURL.substr(schemeEnd + 2, userURL.size());
}

void ClassDesignA::setSchemeEnd(std::string userURL) {
	// 1 is added to give the index including the :
	schemeEnd = userURL.find(":") + 1;
}
void ClassDesignA::setAuthorityStart(std::string brokenURL) {
	// 2 is added to give the index including the //
	authorityEnd = brokenURL.find("/") + 2;
}

void ClassDesignA::setAuthorityEnd(std::string userURL) {
	authorityStart = userURL.find("//");
}

std::string ClassDesignA::getURL() const {
	return userURL;
}

std::string ClassDesignA::getPath() const {
	return path;
}

std::string ClassDesignA::getAuthority() const {
	return authority;
}

std::string ClassDesignA::getScheme() const {
	return scheme;
}

std::string ClassDesignA::getBrokenURL() const {
	return brokenURL;
}

int ClassDesignA::getSchemeEnd() const {
	return schemeEnd;
}

int ClassDesignA::getAuthorityStart() const {
	return authorityStart;
}

int ClassDesignA::getAuthorityEnd() const {
	return authorityEnd;
}

void printClassDesignInfo(const ClassDesignA designA) {
	std::cout << designA.getURL() << "\n" << "Path: " << designA.getPath() << "\n" << "Authority: " <<
		designA.getAuthority() << "\n" << "Scheme: " << designA.getScheme();
}

void printURL(const std::string url) {
	// Pass the URL into the constructor to accesss getter and setter functions
	ClassDesignA designA(url);

	// Set each variable needed to get the different parts of the URL
	designA.setSchemeEnd(url);
	designA.setBrokenURL(url, designA.getSchemeEnd());
	designA.setAuthorityStart(designA.getBrokenURL());
	designA.setAuthorityEnd(url);

	// Set each part of the URL
	designA.setScheme(designA.getSchemeEnd(), designA.getURL());
	designA.setAuthority(designA.getAuthorityStart(), designA.getAuthorityEnd(), designA.getURL());
	designA.setPath(designA.getAuthorityEnd(), designA.getSchemeEnd(), designA.getURL());

	// Print out the URL in the correct format
	std::cout << "URL: " << designA.getURL() << "\n" << "    Scheme: " << designA.getScheme() << "\n" 
		<< "    Authority: " << designA.getAuthority() << "\n" << "    Path: " << designA.getPath() << "\n";
}