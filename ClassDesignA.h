#pragma once
#include <string>

class ClassDesignA {
public:
	ClassDesignA(std::string url);

	std::string getURL() const;
	std::string getPath()  const;
	std::string getScheme() const;
	std::string getAuthority() const;
	std::string getBrokenURL() const;
	int getSchemeEnd() const;
	int getAuthorityStart() const;
	int getAuthorityEnd() const;

	void setPath(int authorityEnd, int schemeEnd, std::string userURL);
	void setAuthority(int authorityStart, int authorityEnd, std::string userURL);
	void setScheme(int schemeEnd, std::string userURL);
	void setBrokenURL(std::string userURL, int schemeEnd);
	void setSchemeEnd(std::string userURL);
	void setAuthorityStart(std::string brokenURL);
	void setAuthorityEnd(std::string userURL);

private:
	// Variable to hold user URL
	std::string userURL;

	// Variables to hold different parts of the user URL
	std::string scheme;
	int schemeEnd;
	std::string authority;
	int authorityStart;
	int authorityEnd;
	std::string path;

	std::string brokenURL;
};

void printClassDesignInfo(const ClassDesignA designA);
void printURL(const std::string url);