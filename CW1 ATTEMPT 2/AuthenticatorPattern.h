#pragma once
#include<iostream>
#include<string>
#include<map>
#include<memory>
#include<vector>

using namespace std;

class Subject
{
private:
	string id;
	string password;
	string proofID;
public:
	Subject(string idName, string pass);
	Subject();
	string getID();
	string getPassword();

	void setProofofIdentification(string proof);
	string getProofofIdentification();
};

Subject::Subject(string aID, string aPass) : id(aID), password(aPass) {
	proofID = "";
}

Subject::Subject() {
	cout << "Enter UserID : ";
	cin >> id;
	cout << "\nEnter Password : ";
	cin >> password;
	proofID = "";
}

string Subject::getID() { return id; };
string Subject::getPassword() { return password; };

void Subject::setProofofIdentification(string proof) {
	proofID = proof;
}

string Subject::getProofofIdentification() {
	return proofID;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class AuthenticationInfo
{
private:
	map<string, string> Users; // User ID and Password
	map<string, string> Admin;
	map<string, string> Manufacturer;

public:

	AuthenticationInfo();
	bool validateUser(string name, string password);
	//bool validateAdmin(string name, string password);
};

AuthenticationInfo::AuthenticationInfo()
{
	Users.insert(pair<string, string>("kappa", "101"));
	Users.insert(pair<string, string>("lambda", "halflife"));
	Users.insert(pair<string, string>("omega", "roundboi"));

};

bool AuthenticationInfo::validateUser(string name, string pass)
{
	bool validUser = false;

	map<string, string>::iterator it;
	it = Users.find(name);

	if (it != Users.end()) {
		if (!(it->second.compare(pass))) {
			validUser = true;
		}
	}
	return validUser;
}




/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class ProofofID
{
private:
	string proofID;
public:
	ProofofID() {};
	ProofofID(string);
	string getProofID();
	void setProofID(string);

};

string ProofofID::getProofID() {
	return proofID;
};

void ProofofID::setProofID(string aproofID) {
	proofID = aproofID;
};

ProofofID::ProofofID(string aproofID) : proofID(aproofID) {};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Authenticator
{
private:
	string encryptDecrypt(string toEncrypyt);
public:
	Authenticator();
	//ProofofID* authenticateUser(Subject &subject);
	ProofofID* authenticateUser(Subject &subject);
};

Authenticator::Authenticator() { };

ProofofID* Authenticator::authenticateUser(Subject &subject)
{
	AuthenticationInfo authInfo;
	ProofofID *proofofID = nullptr;

	string ID = subject.getID();
	string pass = subject.getPassword();
	string token = "";

	if (authInfo.validateUser(ID, pass)) {
		cout << "Welcome!";
		cout << "\nAuthentication Successful!\n";
		token = encryptDecrypt(ID + pass);
		proofofID = new ProofofID(token);
		subject.setProofofIdentification(token);
	}
	else
		cout << "Invalid ID or password... please try again." << endl;
	return proofofID;

};

string Authenticator::encryptDecrypt(string toEncrypt) {
	char key = 'A';
	string output = toEncrypt;
	for (int i = 0; i < toEncrypt.size(); i++) {
		output[i] = toEncrypt[i] ^ key;
	}
	return output;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


