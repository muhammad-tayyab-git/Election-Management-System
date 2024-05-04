#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"
using namespace std;
class PersonalInfo {
protected:
	string name;
	int age;
	string CNIC;
	string gender;
	string address;
	string region;
public:
	PersonalInfo(){
		name="no";
		age=0;
		CNIC="no";
		gender="no";
		address="no";
		region="no";
	}
	void inputData() {
		cin.ignore();
		cout << "Enter Name: ";
		getline(cin, name);
		do{
			cout << "Enter age( Must Be Greater or Equal than 18): ";
			cin >> age;
		}while(age < 18);
		
		cin.ignore();
		cout << "Enter Gender: ";
		getline(cin, gender);
		
		cout << "Enter Address: ";
		getline(cin, address);
		
		cout << "Enter CNIC: ";
		getline(cin, CNIC);
		
	}
	string getName(){
		return name;
	}
	string getCnic(){
		return CNIC;
	}
	string getGender(){
		return gender;
	}
	string getAddress(){
		return address;
	}
	string getRegion(){
		return region;
	}
	
	int getAge(){
		return age;
	}
		void setName(string n){
		name=n;
	}
	
	void setAddress(string add){
		address=add;
	}
	void setGender(string gnd){
		gender=gnd;
	}
	void setCNIC(string cnic){
		CNIC=cnic;
	}
	void setRegion(string reg){
		region=reg;
	}
	void setAge(int a){
		age=a;
	}


};
class	Login {
protected:
	string userName;
	string Password;
public:
	virtual bool login(string,string) = 0; 


	 virtual ~Login() {}

};


class Candidate:public PersonalInfo {
	string partyName;
	string symbol;
	//int obtainedVotes;
public:
	
	void CountVotes() {

	}
	int getCountVotes() {
		return 1;
	}
	string getSymbol(){
		return symbol;
	}
	string getpName(){
		return partyName;
	}
	void setSymbol(string s){
		symbol=s;
	}
	void setPName(string pName){
		partyName=pName;
	}
	Candidate* loadCandidateDataFromFile(int size){
		Candidate *temp=new Candidate[size];
		ifstream inFile("candidate.txt");
		if (inFile.is_open()) {
			for(int i=0;i<size;i++){
				string line;
				if (getline(inFile, line)) {
					stringstream ss(line);
					string ageStr;
					getline(ss, temp[i].name, ',');
					getline(ss, ageStr, ',');
					getline(ss, temp[i].CNIC, ',');
					getline(ss, temp[i].gender, ',');
					getline(ss, temp[i].address, ',');
					getline(ss, temp[i].region, ',');
					getline(ss, temp[i].partyName, ',');
					
					getline(ss, temp[i].symbol);
					
					//getline(ss,obtainedVotesStr);
					temp[i].age=stoi(ageStr);
					//temp[i].obtainedVotes=stoi(obtainedVotesStr);
					
				} else {
					cout << "Error reading line from file(loadACandidateDataFromFile).\n";
					
				}
			}
			
			inFile.close();
		} else {
			cout << "Error in opening File(candidate.txt).\n";
			
		}
		return temp;
	}
	


};

class Result{
	string region;
	int regdVote;
	int castVote;
	string candidate;
	string party;
	int votes;
	public:
		
		string getRegion(){
			return region;
		}
		int getRegdVote(){
			return regdVote;
		}
		int getCastVote(){
			return castVote;
		}
		string getCandidate(){
			return candidate;
		}
		string getParty(){
			return party;
		}
		int getVotes(){
			return votes;
		}
		
		void setRegion(string reg){
			 region=reg;
		}
		void setRegdVote(int r){
			 regdVote=r;
		}
		void setCastVote(int c){
			 castVote=c;
		}
		void setCandidate(string c){
			 candidate=c;
		}
		void setParty(string p){
			 party=p;
		}
		void setVotes(int v){
			votes=v;
		}
		Result* loadresultDataFromFile(int size){
			Result *temp=new Result[size];
			ifstream inFile("result.txt");
			if (inFile.is_open()) {
				for(int i=0;i<size;i++){
					string line;
					if (getline(inFile, line)) {
						stringstream ss(line);
						string regdStr,castVoteStr,votesStr;
						getline(ss, temp[i].region, ',');
						getline(ss, regdStr, ',');
						getline(ss, castVoteStr, ',');
						getline(ss, temp[i].candidate, ',');
						getline(ss, temp[i].party, ',');
						getline(ss, votesStr);
						
						temp[i].regdVote=stoi(regdStr);
						temp[i].castVote=stoi(castVoteStr);
						temp[i].votes=stoi(votesStr);
						
					} else {
						cout << "Error reading line from file(loadResultDataFromFile).\n";
						
					}
				}
				
				inFile.close();
			} else {
				cout << "Error in opening File(result.txt).\n";
				
			}
			return temp;
		}
		void writeResult(Result* result, int size) {
			ofstream outFile("result.txt");
			if (!outFile) {
				cout << "Error in opening File(candidate.txt" << endl;
				return;
			}
			for (int i = 0; i < size; i++) {
				outFile << result[i].getRegion() << "," << result[i].getRegdVote() << "," << result[i].getCastVote() << "," << result[i].getCandidate() << "," 
				<< result[i].getParty() << "," << result[i].getVotes()<< endl;
			}
			outFile.close();
		}
		void showPartyresult(Result* result,int rSize,string reg,string name,string p,string sym){
			
			for(int i=0;i<rSize;i++){
				if(result[i].getRegion()==reg && result[i].getParty()==p){
					
					cout << left << setw(25) << name << left << setw(25) << p << left << setw(25) << sym << left << setw(20) << result[i].getVotes()  << endl;
				}
			}
			
	}
	
	void showRegionResult(Candidate* cand,int cSize,Result* result,int rSize,string reg){
	
		cout <<"\t\t\t" << YELLOW <<reg<< RESET <<endl;
		cout<<"\t\t\t-----"<<endl;
		//int stop=0;
		string pg;
		for(int i=0;i<cSize;i++){
			if(cand[i].getRegion()==reg){
		
				 pg=cand[i].getpName();
				
				if(result[i].getParty()==pg && result[i].getRegion()==reg){
					cout<<"Registered Voter: "<<result[i].getRegdVote()<<"\t\t"<<"Vote-Casted: "<<result[i].getCastVote()<<endl<<endl;
					cout << left << setw(25) << "Candidate" << left << setw(25) << "Party" << left << setw(25) << "Symbol" << left << setw(20) << "Votes"  << endl;	
					break;
				}
			
			}
		
		}
		
		for(int i=0;i<cSize;i++){
			if(cand[i].getRegion()==reg){
				string n=cand[i].getName();
				string p=cand[i].getpName();
				string s=cand[i].getSymbol();
				
			
				showPartyresult(result,rSize,reg,n,p,s);
			}
		}
		
		
		
	}
		
	
		
		
};



class Voter :public PersonalInfo {
	int hasVoted;
public:
	
	int getHasVoted(){
		return hasVoted;
	}
	
	
	Voter* loadVoterDataFromFile(int size){
		Voter *temp=new Voter[size];
		ifstream inFile("voter.txt");
		if (inFile.is_open()) {
			for(int i=0;i<size;i++){
				string line;
				if (getline(inFile, line)) {
					stringstream ss(line);
					string ageStr,hasVotedStr;
					getline(ss, temp[i].name, ',');
					getline(ss, ageStr, ',');
					getline(ss, temp[i].CNIC, ',');
					getline(ss, temp[i].gender, ',');
					getline(ss, temp[i].address, ',');
					getline(ss, temp[i].region, ',');
				
					getline(ss,hasVotedStr);
					temp[i].hasVoted=stoi(hasVotedStr);
					//getline(ss,obtainedVotesStr);
					temp[i].age=stoi(ageStr);
					//temp[i].obtainedVotes=stoi(obtainedVotesStr);
					
				} else {
					cout << "Error reading line from file(loadACandidateDataFromFile).\n";
					
				}
			}
			
			inFile.close();
		} else {
			cout << "Error in opening File(candidate.txt).\n";
			
		}
		return temp;
	}
	void viewCandidates(Candidate* cand,int size){
		cout<<"candidates List: "<<endl ;
		cout<<"---------------"<<endl ;
		
		int c=1;
		cout << left << setw(15) << "Candidate" << left << setw(15) << "Party" << left << setw(20) << "Symbol"  << endl;
		for(int i=0;i<size;i++){
			if(cand[i].getRegion()==this->region){
				cout << left << setw(15) << cand[i].getName() << left << setw(15) << cand[i].getpName() << left << setw(20) << cand[i].getSymbol() << endl;
				c++;
			}
			
		}
		if(c==1){
			cout << BG_WHITE << RED << " !!!There is no Candidate in this region.!!! " << RESET << endl;
		}
	}
		
	void castVote(Candidate* cand,int cSize,Result* result,int rSize){
		if(this->getHasVoted()==0){
			cout<<"candidates List: "<<endl ;
			cout<<"---------------"<<endl ;
			string p;
			int c=1,check=0;
			cout << left << setw(15) << "Candidate" << left << setw(15) << "Party" << left << setw(20) << "Symbol"  << endl;
			for(int i=0;i<cSize;i++){
				if(cand[i].getRegion()==this->region){
					cout << left << setw(15) << cand[i].getName() << left << setw(15) << cand[i].getpName() << left << setw(20) << cand[i].getSymbol() << endl;
					c++;
				}
				
			}
			if(c==1){
				cout << BG_WHITE << RED << " !!!There is no Candidate in this region.!!! " << RESET << endl;;
			}
			do{
				cout<<"Enter the party Name You want to give Vote(As same as Shown): ";
				cin>>p;
				for(int i=0;i<cSize;i++){
					if(cand[i].getRegion()==this->region && cand[i].getpName()==p){
						check=1;
						break;
					}
				}
			}while(check != 1);
			
			if(check==1){
				this->hasVoted=1;
				for(int i=0;i<rSize;i++){
					if(result[i].getRegion()==this->region){
						int cv=result[i].getCastVote();
						cv++;
						result[i].setCastVote(cv);
						if(result[i].getParty()==p){
							int gv=result[i].getVotes();
							gv++;
							result[i].setVotes(gv);
						}
						
					}
				}
				cout << BG_BLACK  << GREEN << " *****Your Vote is Casted.***** " << RESET << endl<<endl;
			}
		}else{
			cout << BG_WHITE << RED << " !!!You have already cast the vote.!!! " << RESET << endl;
		}
	}
	void writeVoterData(Voter* voter,int size){
		ofstream outFile("voter.txt");
		if (!outFile) {
			cout << "Error in opening File(candidate.txt" << endl;
			return;
		}
		for (int i = 0; i < size; i++) {
			outFile << voter[i].getName() << "," << voter[i].getAge() << "," << voter[i].getCnic() << "," << voter[i].getGender() << "," 
			<< voter[i].getAddress() << "," << voter[i].getRegion() << "," << voter[i].getHasVoted()<< endl;
		}
		outFile.close();
	}
		
};


class PresidingOfficer :public PersonalInfo ,public  Login{

public:
	
	string getUsername(){
		return userName;
	}
	string getPassword(){
	return Password;
	}
	bool login(string uName,string psw) override{
		if (uName == this->userName && psw == this->Password) {
			return true;
		}
		return false;
	}
	void setUsername(string uName){
		userName=uName;
	}
	void setPsw(string Psw){
		Password=Psw;
	}
	
	void viewCandidates(Candidate* cand,int size) {
		cout<<"candidates List: "<<endl ;
		cout<<"---------------"<<endl ;
		int c=1;
		cout << left << setw(15) << "Candidate" << left << setw(15) << "CNIC" << left << setw(15) << "Party" << left << setw(20) << "Symbol"  << endl;
		for(int i=0;i<size;i++){
			if(cand[i].getRegion()==this->region){
				cout << left << setw(15) << cand[i].getName() << left << setw(15) << cand[i].getCnic() << left << setw(15) << cand[i].getpName() << left << setw(20) << cand[i].getSymbol() << endl;
				c++;
			}
			
		}
		if(c==1){
			cout << BG_WHITE << RED << " !!!There is no Candidate in this region.!!! " << RESET << endl;
		}
	}
	void viewVoter(Voter* voter,int size) {
		cout<<"Voter List: "<<endl ;
		cout<<"---------"<<endl ;
		int c=1;
		cout << left << setw(15) << "Name" << left << setw(15) << "CNIC" << left << setw(20) << "Address"  << endl;
		for(int i=0;i<size;i++){
			if(voter[i].getRegion()==this->region){
				cout << left << setw(15) << voter[i].getName() << left << setw(15) << voter[i].getCnic() << left << setw(20) << voter[i].getAddress() << endl;
				c++;
			}
			
		}
		if(c==1){
			cout << BG_WHITE << RED << " !!!There is no Voter.!!! " << RESET << endl;
		}
	}
	bool checkParty(Candidate* cand,int size,string p,string reg){
		for(int i=0;i<size;i++){
			if(cand[i].getpName()==p && cand[i].getRegion()==reg){
				return true;
			}
		}
		return false;
	}
	bool checkSymbol(Candidate* cand,int size,string s,string reg){
		for(int i=0;i<size;i++){
			if(cand[i].getSymbol()==s && cand[i].getRegion()==reg){
				return true;
			}
		}
		return false;
	}
	bool checkCnic(Candidate* cand,int size,string cnic,string reg){
		for(int i=0;i<size;i++){
			if(cand[i].getCnic()==cnic && cand[i].getRegion()==reg){
				return true;
			}
		}
		return false;
	}
	
	Candidate* addCandidates(Candidate* cand,int& size) {
		
		Candidate* temp = new Candidate[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = cand[i];
		}
		string pName,symbl;
		temp[size].inputData();
		
		string cnic=temp[size].getCnic();
		if(checkCnic(cand,size,cnic,region)){
			cout << BG_WHITE << RED << " !!!The Candidate with this CNIC Already Existed.!!! " << RESET << endl;
			cout<<"Please Enter new CNIC: ";
			getline(cin, cnic);
		}
		temp[size].setCNIC(cnic);
		temp[size].setRegion(region);
		cout << "Enter Party Name(Can't be Modified): ";
		getline(cin, pName);
		if(checkParty(cand,size,pName,region)){
			cout << BG_WHITE << RED << " !!!This Party is already existed.!!! " << RESET << endl;
			cout<<"Please Enter new Party Name: ";
			getline(cin, pName);
		}
		temp[size].setPName(pName);
		cout << "Enter Party Symbol(Can't be Modified): ";
		getline(cin, symbl);
		if(checkSymbol(cand,size,symbl,region)){
			cout << BG_WHITE << RED << " !!!This Party is already existed.!!! " << RESET << endl;
			cout<<"Please Enter new Symbol: ";
			getline(cin, symbl);
		}
		temp[size].setSymbol(symbl);
	
		
		cout << BG_BLACK  << GREEN << " *****Candidate Added Successfully.***** " << RESET << endl;
		cout << endl;
		size++;

		delete[] cand;
		writeCandidateDataToFile(temp, size);
		return temp;
	}

	
	void candidateDataToResult(Candidate* cand,int size,Voter* voter,int vSize) {
	
			ofstream outFile("result.txt",ios::app);
			if (!outFile) {
				cout << "Error in opening File(candidate.txt" << endl;
				return;
			}
			int v=0;
			for(int i=0;i<vSize;i++){
				if(voter[i].getRegion()==cand[size-1].getRegion()){
					v++;
				}
			}
			
			
				
			outFile << cand[size-1].getRegion() << "," << v << "," << 0 << "," << cand[size-1].getName() << "," 
			<< cand[size-1].getpName() << "," << 0<< endl;
			
			outFile.close();
	}
		
		
	
	void writeCandidateDataToFile(Candidate* cand, int size) {
		ofstream outFile("candidate.txt");
		if (!outFile) {
			cout << "Error in opening File(candidate.txt" << endl;
			return;
		}
		for (int i = 0; i < size; i++) {
			outFile << cand[i].getName() << "," << cand[i].getAge() << "," << cand[i].getCnic() << "," << cand[i].getGender() << "," 
			<< cand[i].getAddress() << "," << cand[i].getRegion() << "," << cand[i].getpName()<< "," << cand[i].getSymbol() << endl;
		}
		outFile.close();
	}

	bool checkCnic(Voter* voter,int size,string cnic){
		for(int i=0;i<size;i++){
			if(voter[i].getCnic()==cnic){
				return true;
			}
		}
		return false;
	}

	Voter* addVoter(Voter* voter,int& size,Result* result,int rSize) {
		Voter* temp = new Voter[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = voter[i];
		}
		temp[size].inputData();
		string cnic=temp[size].getCnic();
		if(checkCnic(voter,size,cnic)){
			cout << BG_WHITE << RED << " !!!The Voter with this CNIC Already Existed.!!! " << RESET << endl;
			cout<<"Please Enter new CNIC: ";
			getline(cin, cnic);
		}
		temp[size].setCNIC(cnic);
		temp[size].setRegion(region);
		cout << BG_BLACK  << GREEN << " *****Voter Added Successfully.***** " << RESET << endl;
		cout << endl;
		
		for (int i = 0; i < rSize; i++) {
			if(result[i].getRegion()==region){
				int c=0;
				c=result[i].getRegdVote();
				c++;
				result[i].setRegdVote(c);
			}
		}
		size++;
		
		delete[] voter;
		writeVoterDataToFile(temp, size);
		return temp;
	}
	void writeVoterDataToFile(Voter* voter, int size) {
		ofstream outFile("voter.txt");
		if (!outFile) {
			cout << "Error in opening File(candidate.txt" << endl;
			return;
		}
		for (int i = 0; i < size; i++) {
			outFile << voter[i].getName() << "," << voter[i].getAge() << "," << voter[i].getCnic() << "," << voter[i].getGender() << "," 
			<< voter[i].getAddress() << "," << voter[i].getRegion() << "," << 0<< endl;
		}
		outFile.close();
	}
	int  getCnicIndex(Candidate* cand, int size){
		string cnic;
		cout<<"Enter CNIC of Candidate You want to update INFO: ";
		cin>>cnic;
		
		for(int i=0;i<size;i++){
			if(cand[i].getCnic()==cnic){
				return i;
			}
		
		}
			return -1;
	}
	bool checkCnic(Candidate* cand,int size,string cnic){
		for(int i=0;i<size;i++){
			if(cand[i].getCnic()==cnic){
				return true;
			}
		}
		return false;
	}
	void updateCandidate(Candidate* cand, int size) {
		int i=getCnicIndex(cand,size);
		cout<<endl;
		if(i != -1){
			cout<<"Name: "<<cand[i].getName()<<endl;
			cout<<"Age: "<<cand[i].getAge()<<endl;
			cout<<"Gender: "<<cand[i].getGender()<<endl;
			cout<<"Address: "<<cand[i].getAddress()<<endl;
			cout<<"CNIC: "<<cand[i].getCnic()<<endl;
			char choice;
			
			do{
				cout<<endl;
				cout<<"-----Update Candidate Info-----"<<endl;
				cout<<"======================================"<<endl;
				cout<<"1-Update Name"<<endl;
				cout<<"2-Update Age"<<endl;
				cout<<"3-Update Gender"<<endl;
				cout<<"4-Update Address"<<endl;
				cout<<"5-Update CNIC"<<endl;
				cout<<"6-Exit"<<endl;
				cout<<"======================================"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>choice;
				cout<<"======================================"<<endl;
				string n,add,cnic,g,uName;
				int a;
				switch(choice){
					case '1':
						cin.ignore();
						cout<<"Enter New Name: ";
						getline(cin,n);
						cand[i].setName(n);
						break;
					case '2':
						cout<<"Enter New Age: ";
						cin>>a;
						cand[i].setAge(a);
						cin.ignore();
						break;
					case '3':
						cout<<"Enter New Gender: ";
						cin>>g;
						cand[i].setGender(g);
						break;
					case '4':
						cout<<"Enter New Address: ";
						cin>>add;
						cand[i].setAddress(add);
						break;
					case '5':
						cout<<"Enter New CNIC: ";
						cin>>cnic;
						
						if(checkCnic(cand,size,cnic)){
							cin.ignore();
							cout << "CNIC must be Unique(Enter New CNIC): ";
							getline(cin, cnic);
						}
						cand[i].setCNIC(cnic);
						break;
				
					case '6':
						cout<<endl;
						cout<<"Exiting..."<<endl;
						cout<<endl;
						break;
					default:
						cout << BG_WHITE << RED << " !!!Invalid Number.!!! " << RESET << endl;
						break;
				}
			}while(choice != '6');
		}else{
			cout << BG_WHITE << RED << " !!!The Candidate with this CNIC does not exists.!!! " << RESET << endl;
		
		}
	}
	
	int  getVoterCnicIndex(Voter* voter, int size){
		string cnic;
		cout<<"Enter CNIC of Voter You want to update INFO: ";
		cin>>cnic;
		
		for(int i=0;i<size;i++){
			if(voter[i].getCnic()==cnic){
				return i;
			}
		
		}
			return -1;
	}
	void updateVoter(Voter* voter, int size) {
		int i=getVoterCnicIndex(voter,size);
		cout<<endl;
		if(i != -1){
			cout<<"Name: "<<voter[i].getName()<<endl;
			cout<<"Age: "<<voter[i].getAge()<<endl;
			cout<<"Gender: "<<voter[i].getGender()<<endl;
			cout<<"Address: "<<voter[i].getAddress()<<endl;
			cout<<"CNIC: "<<voter[i].getCnic()<<endl;
			char choice;
			
			do{
				cout<<endl;
				cout<<"-----Update Voter Info-----"<<endl;
				cout<<"======================================"<<endl;
				cout<<"1-Update Name"<<endl;
				cout<<"2-Update Age"<<endl;
				cout<<"3-Update Gender"<<endl;
				cout<<"4-Update Address"<<endl;
				cout<<"5-Update CNIC"<<endl;
				cout<<"6-Exit"<<endl;
				cout<<"======================================"<<endl;
			
				cout<<"Enter Your Choice: ";
				cin>>choice;
				cout<<"======================================"<<endl;
				string n,add,cnic,g,uName;
				int a;
				switch(choice){
					case '1':
						cin.ignore();
						cout<<"Enter New Name: ";
						getline(cin,n);
						voter[i].setName(n);
						break;
					case '2':
						cout<<"Enter New Age: ";
						cin>>a;
						voter[i].setAge(a);
						cin.ignore();
						break;
					case '3':
						cout<<"Enter New Gender: ";
						cin>>g;
						voter[i].setGender(g);
						break;
					case '4':
						cout<<"Enter New Address: ";
						cin>>add;
						voter[i].setAddress(add);
						break;
					case '5':
						cout<<"Enter New CNIC: ";
						cin>>cnic;
						
						if(checkCnic(voter,size,cnic)){
							cin.ignore();
							cout << "CNIC must be Unique(Enter New CNIC): ";
							getline(cin, cnic);
						}
						voter[i].setCNIC(cnic);
						break;
				
					case '6':
						cout<<endl;
						cout<<"Exiting..."<<endl;
						cout<<endl;
						break;
					default:
						cout << BG_WHITE << RED << " !!!Invalid Number.!!! " << RESET << endl;
						break;
				}
			}while(choice != '6');
		}else{
			cout << BG_WHITE << RED << " !!!The Voter with this CNIC does not exists.!!! " << RESET << endl;
		}
	}
	
	int getDeletingVoterIndex(Voter* voter, int size,string cnic){
		
		
		for(int i=0;i<size;i++){
			if(voter[i].getCnic()==cnic && voter[i].getRegion()==this->region){
				return i;
			}
		
		}
			return -1;
	}
	int getDeletingCandidateIndex(Candidate* cand, int size,string cnic){
		
		
		for(int i=0;i<size;i++){
			if(cand[i].getCnic()==cnic && cand[i].getRegion()==this->region){
				return i;
			}
		
		}
			return -1;
	}
	Voter* deleteVoter(Voter* voter, int& vSize,Result* result,int rSize) {
		string cnic;
		cout<<"Enter the CNIC of Voter You want to delete: ";
		cin>>cnic;
		int voterTodelete=getDeletingVoterIndex(voter,vSize,cnic);
		if(voterTodelete != -1){
			Voter* temp=new Voter[vSize-1];
			 int tempIndex = 0;
			for (int i = 0; i < vSize; i++) {
				if (i != voterTodelete) {
					temp[tempIndex++] = voter[i];
				}
			}
			vSize--;
			delete[] voter;
			cout << BG_BLACK  << GREEN << " *****Voter Removed Successfully.***** " << RESET << endl;
			
			for(int i=0;i<rSize;i++){
				if(result[i].getRegion()==this->region){
					int c=result[i].getRegdVote();
					if(c != 0){
						c--;
					}
					result[i].setRegdVote(c);
				}
			}
			return temp;
		}else{
			cout << BG_WHITE << RED << " !!!The voter with this CNIC does not exists in this Region!!! " << RESET << endl;
		
			return voter;
		}
		
	}

	Candidate* deleteCandidate(Candidate* cand, int& cSize,Result* result,int& rSize,int candTodelete) {
		
		if(candTodelete != -1){
			Candidate* temp=new Candidate[cSize-1];
			 int tempIndex = 0;
			for (int i = 0; i < cSize; i++) {
				if (i != candTodelete) {
					temp[tempIndex++] = cand[i];
				}
			}
			ofstream outFile("result.txt");
			if (!outFile) {
				cout << "Error in opening File(result.txt)" << endl;
				
			}
			for(int i=0;i<rSize;i++){
				if(result[i].getRegion() != this->region || result[i].getParty() != cand[candTodelete].getpName()){	
					outFile << result[i].getRegion() << "," << result[i].getRegdVote() << "," << result[i].getCastVote() << "," << result[i].getCandidate() << "," 
					<< result[i].getParty() << "," << result[i].getVotes()<< endl;
				}
			}
			
			
			outFile.close();
			
			cSize--;
			rSize--;
			
			delete[] cand;
			cout << BG_BLACK  << GREEN << " *****Candidate Removed Successfully.***** " << RESET << endl;
		
			return temp;
		}else{
			cout << BG_WHITE << RED << " !!!The Candidate with this CNIC does not exists in this Region.!!! " << RESET << endl;
			return cand;
		}
		
	}
	
	 PresidingOfficer* changePassword(PresidingOfficer* po,int size){
		 string cnic;
		  cin.ignore();
		 cout<<"Enter Your CNIC: ";
		  getline(cin,cnic);
		  
		   
		 int index=-1;
		
		 for(int i=0;i<size;i++){
			 if(po[i].getCnic()==cnic && this->getCnic()==cnic){
				 index=i;
				 break;
			 }
		 }
		 if(index != -1){
			 cout<<"Your Previous Password is: "<<po[index].getPassword()<<endl;
			 string pass;
			 cout<<"Enter New Password: ";
			 getline(cin,pass);
			 po[index].setPsw(pass);
			 
			 cout << BG_BLACK  << GREEN << " *****Password Updated Successfuly.***** " << RESET << endl;
			 ofstream outFile("po.txt");
			if (!outFile) {
				cout << "Error in opening File" << endl;
				
			}
			for (int i = 0; i < size; i++) {
				outFile << po[i].getName() << "," << po[i].getAge() << "," << po[i].getCnic() << "," << po[i].getGender() << "," << po[i].getAddress() << "," << po[i].getRegion()<< "," << po[i].getUsername() << "," << po[i].getPassword() << endl;
			}
			outFile.close();
			 return po;
			 
		 }else{
			 cout << BG_WHITE << RED << " !!!Wrong CNIC.!!! " << RESET << endl;
			 return po;
		 }
		 
		 
	 }




	
	PresidingOfficer* loadPoDataFromFile(int size){
		PresidingOfficer *temp=new PresidingOfficer[size];
		ifstream inFile("po.txt");
		if (inFile.is_open()) {
			for(int i=0;i<size;i++){
				string line;
				if (getline(inFile, line)) {
					stringstream ss(line);
					string ageStr;
					getline(ss, temp[i].name, ',');
					getline(ss, ageStr, ',');
					getline(ss, temp[i].CNIC, ',');
					getline(ss, temp[i].gender, ',');
					getline(ss, temp[i].address, ',');
					getline(ss, temp[i].region, ',');
					
					getline(ss, temp[i].userName, ',');
					getline(ss, temp[i].Password);
					temp[i].age=stoi(ageStr);
					
				} else {
					cout << "Error reading line from file(loadPODataFromFile).\n";
					
				}
			}
			
			inFile.close();
		} else {
			cout << "Error in opening File(po.txt).\n";
			
		}
		return temp;
	}
	
	
	//virtual ~PresidingOfficer(){}


};


	
	



class ElectionCommission : public Login {
private:
	Result resObj;
public:
	ElectionCommission(){
		userName="admin";
		Password="1234";
	}
	void showResult(PresidingOfficer* po,int pSize,Result* result,int rSize,Candidate* cand,int cSize){
	cout<<endl;
	cout << setw(20) << BG_WHITE << BLACK  << " Result of each Region "<<RESET << endl;
	string reg;
	for(int i=0;i<pSize;i++){
		reg=po[i].getRegion();
		resObj.showRegionResult(cand,cSize,result,rSize,reg);
	}
}
	ElectionCommission* loadAdminDataFromFile(){
		ElectionCommission *temp=new ElectionCommission;
		ifstream inFile("admin.txt");
		if (inFile.is_open()) {
				string line;
				if (getline(inFile, line)) {
					stringstream ss(line);
					getline(ss, temp->userName, ',');
					getline(ss, temp->Password);
				  
					
				} else {
					cout << "Error reading line from file(loadAdminDataFromFile).\n";
					
				}
			
			inFile.close();
		} else {
			cout << "Error in opening File(admin.txt).\n";
			
		}
		return temp;
	}
	bool login(string uName, string psw) override {
		if (uName == this->userName && psw == this->Password) {
			return true;
		}
		return false;
	}
	bool checkCnic(PresidingOfficer* po, int size,string cnic){
		for(int i=0;i<size;i++){
			if(po[i].getCnic()==cnic){
				return true;
			}
		}
		return false;
	}
	bool checkUser(PresidingOfficer* po, int size,string uName){
		for(int i=0;i<size;i++){
			if(po[i].getUsername()==uName){
				return true;
			}
		}
		return false;
	}
	
	PresidingOfficer* addPo(PresidingOfficer* po, int& size) {
		PresidingOfficer* temp = new PresidingOfficer[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = po[i];
		}
		string n, cnic, gndr, add, reg,uName,Psw;
		int ag;
		cout << "Enter the details of Presiding Officer." << endl;
		cin.ignore();
		cout << "Enter Name: ";
		getline(cin, n);
		temp[size].setName(n);
		//getline(cin,temp[size].name)
		
		do{
			cout << "Enter age(Must be 18): ";
			cin >> ag;
		}while(ag < 18);
		temp[size].setAge(ag);
		cin.ignore();
		cout << "Enter CNIC: ";
		getline(cin, cnic);
		if(checkCnic(po,size,cnic)){
			//cin.ignore();
			cout << "CNIC must be Unique(Enter New CNIC): ";
			getline(cin, cnic);
		}
		temp[size].setCNIC(cnic);
		cout << "Enter Gender: ";
		getline(cin, gndr);
		temp[size].setGender(gndr);
		cout << "Enter Address: ";
		getline(cin, add);
		temp[size].setAddress(add);
		cout << "Enter Region(Please Enter this field Correctly-You could not Update it Later): ";
		getline(cin, reg);
		temp[size].setRegion(reg);
		
		cout<<"Also Provide log in functionality to presiding officer."<<endl;
		cout<<"Enter Username: ";
		cin>>uName;
		if(checkUser(po,size,uName)){
			cout<<"Already Existed.Enter New Username: ";
			cin>>uName;
		}
		temp[size].setUsername(uName);
		cout<<"Enter Password: ";
		cin>>Psw;
		temp[size].setPsw(Psw);
		
		cout << BG_BLACK  << GREEN << " *****Presiding Officer Added Successfully.***** " << RESET << endl;
		cout << endl;
		size++;

		delete[] po;
		writePoDataToFile(temp, size);
		return temp;
	}

	void writePoDataToFile(PresidingOfficer* po, int size) {
		ofstream outFile("po.txt");
		if (!outFile) {
			cout << "Error in opening File" << endl;
			return;
		}
		for (int i = 0; i < size; i++) {
			outFile << po[i].getName() << "," << po[i].getAge() << "," << po[i].getCnic() << "," << po[i].getGender() << "," << po[i].getAddress() << "," << po[i].getRegion()<< "," << po[i].getUsername() << "," << po[i].getPassword() << endl;
		}
		outFile.close();
	}
	
	int  getCnicIndex(PresidingOfficer* po,int size){
		string cnic;
		cout<<"Enter CNIC of PO You want to update INFO: ";
		cin>>cnic;
		
		for(int i=0;i<size;i++){
			if(po[i].getCnic()==cnic){
				return i;
			}
		
		}
			return -1;
	}
	void  updatePo(PresidingOfficer* po,int size) {
		int i=getCnicIndex(po,size);
		cout<<endl;
		if(i != -1){
			cout<<"Name: "<<po[i].getName()<<endl;
			cout<<"Age: "<<po[i].getAge()<<endl;
			cout<<"Gender: "<<po[i].getGender()<<endl;
			cout<<"Address: "<<po[i].getAddress()<<endl;
			cout<<"CNIC: "<<po[i].getCnic()<<endl;
			cout<<"Username: "<<po[i].getUsername()<<endl;
			char choice;
			
			do{
				cout<<endl;
				cout<<"-----Update PO Info-----"<<endl;
				cout<<"======================================"<<endl;
				cout<<"1-Update Name"<<endl;
				cout<<"2-Update Age"<<endl;
				cout<<"3-Update Gender"<<endl;
				cout<<"4-Update Address"<<endl;
				cout<<"5-Update CNIC"<<endl;
				cout<<"6-Update Username"<<endl;
				cout<<"7-Exit"<<endl;
				cout<<endl;
				cout<<"======================================"<<endl;
				cout<<"Enter Your Choice: ";
				cin>>choice;
				cout<<"======================================"<<endl;
				string n,add,cnic,g,uName;
				int a;
				switch(choice){
					case '1':
						cin.ignore();
						cout<<"Enter New Name: ";
						getline(cin,n);
						po[i].setName(n);
						break;
					case '2':
						cout<<"Enter New Age: ";
						cin>>a;
						po[i].setAge(a);
						cin.ignore();
						break;
					case '3':
						cout<<"Enter New Gender: ";
						cin>>g;
						po[i].setGender(g);
						break;
					case '4':
						cout<<"Enter New Address: ";
						cin>>add;
						po[i].setAddress(add);
						break;
					case '5':
						cout<<"Enter New CNIC: ";
						cin>>cnic;
						if(checkCnic(po,size,cnic)){
							cout << "CNIC must be Unique(Enter New CNIC): ";
							getline(cin, cnic);
						}
						po[i].setCNIC(cnic);
						break;
					case '6':
						cout<<"Enter New Username: ";
						cin>>uName;
						if(checkUser(po,size,uName)){
							cout<<"Already Existed.(Enter New Username): ";
							cin>>uName;
						}
						po[i].setUsername(uName);
						break;
					case '7':
						cout<<endl;
						cout<<"Exiting..."<<endl;
						cout<<endl;
						break;
					default:
						cout << BG_WHITE << RED << " !!!Invalid Number.!!! " << RESET << endl;
						break;
				}
			}while(choice != '7');
		}else{
			cout << BG_WHITE << RED << " !!!The PO with this CNIC does not exists.!!! " << RESET << endl;
		}
	}
	void viewPo(PresidingOfficer* po,int size) {
		cout<<"Presiding Officers Detail: "<<endl ;
		int c=1;
		cout << left << setw(15) << "Name" << left << setw(15) << "CNIC" << left << setw(20) << "Region"  << endl;
		for(int i=0;i<size;i++){
				cout << left << setw(15) << po[i].getName() << left << setw(15) << po[i].getCnic() << left << setw(20) << po[i].getRegion() << endl;
				c++;
			
			
		}
		if(c==1){
			cout << BG_WHITE << RED << " !!!There is no Presiding Officer.!!! " << RESET << endl;
		}
	}
	int getDeletingPoIndex(PresidingOfficer* po,int size,string cnic){
		
		
		for(int i=0;i<size;i++){
			if(po[i].getCnic()==cnic){
				return i;
			}
		
		}
			return -1;
	}
	
	PresidingOfficer* deletePo(PresidingOfficer* po,int& pSize,Result* result,int rSize,Candidate* cand,int cSize,Voter* voter, int vSize,int poTodelete) {
	
		if(poTodelete != -1){
			PresidingOfficer* temp=new PresidingOfficer[pSize-1];
			 int tempIndex = 0;
			for (int i = 0; i < pSize; i++) {
				if (i != poTodelete) {
					temp[tempIndex++] = po[i];
					
				}
			}
			
			ofstream resultFile("result.txt");
		
			
			if (!resultFile) {
				cout << "Error in opening Files(resPoDel.txt)" << endl;
				
			}
			
			for(int i=0;i<rSize;i++){
				
				if(result[i].getRegion() != po[poTodelete].getRegion()){	
					cout<<result[i].getRegion()<<"="<<po[poTodelete].getRegion()<<endl;
					resultFile << result[i].getRegion() << "," << result[i].getRegdVote() << "," << result[i].getCastVote() << "," << result[i].getCandidate() << "," 
					<< result[i].getParty() << "," << result[i].getVotes()<< endl;
				}
			}
			resultFile.close();
			ofstream candFile("candidate.txt");
			if (!candFile) {
				cout << "Error in opening Files(cand/poDel.txt)" << endl;
				
			}
			for(int i=0;i<cSize;i++){
				if(cand[i].getRegion() != po[poTodelete].getRegion()){	
					cout<<cand[i].getRegion()<<"="<<po[poTodelete].getRegion()<<endl;
					candFile << cand[i].getName() << "," << cand[i].getAge() << "," << cand[i].getCnic() << "," << cand[i].getGender() << "," 
					<< cand[i].getAddress() << "," << cand[i].getRegion() << "," << cand[i].getpName()<< "," << cand[i].getSymbol() << endl;
				}
			}
			candFile.close();
			cout<<"Yes"<<endl;
			ofstream voterFile("voter.txt");
			if (!voterFile) {
				cout << "Error in opening Files(voter/delPO.txt)" << endl;
				
			}
			for(int i=0;i<vSize;i++){
				if(voter[i].getRegion() != po[poTodelete].getRegion()){	
					cout<<voter[i].getRegion()<<"="<<po[poTodelete].getRegion()<<endl;
					voterFile << voter[i].getName() << "," << voter[i].getAge() << "," << voter[i].getCnic() << "," << voter[i].getGender() << "," 
					<< voter[i].getAddress() << "," << voter[i].getRegion() << "," << voter[i].getHasVoted() << endl;
				}
			}
			
			
			
			voterFile.close();
			cout<<"Yes"<<endl;
			pSize--;
			
			
			delete[] po;
			cout << BG_BLACK  << GREEN << " *****PO Removed Successfully.***** " << RESET << endl;
		
			return temp;
		}else{
			cout << BG_WHITE << RED << " !!!The PO with this CNIC does not exists in Database.!!! " << RESET << endl;
			return po;
		}
		
	}
	
	
	
	
	
	
	

	
};

int findFileSize(const string& filename){
	int size=0;
	ifstream inFile(filename);
	if(!inFile){
		cout<<"Error opening File.";
		return size;
	}
	
	string line;
	while(getline(inFile,line)){
		size++;
	}
	return size;
	
}
int main() {
	Login *l;
	//ElectionCommission e;
	ElectionCommission *ec=new ElectionCommission;
	//ec=ec->loadAdminDataFromFile();
	
	int poFileSize=findFileSize("po.txt");
	PresidingOfficer *po=new PresidingOfficer[poFileSize];
	po=po->loadPoDataFromFile(poFileSize);
	PresidingOfficer *loggedPo=nullptr;
	
	int candidateFileSize=findFileSize("candidate.txt");
	Candidate *candidate=new Candidate[candidateFileSize];
	candidate=candidate->loadCandidateDataFromFile(candidateFileSize);
	
	int voterFileSize=findFileSize("voter.txt");
	Voter *voter=new Voter[voterFileSize];
	voter=voter->loadVoterDataFromFile(voterFileSize);
	Voter *loggedVoter=nullptr;
	
	int resultFileSize=findFileSize("result.txt");
	Result *result=new Result[resultFileSize];
	result=result->loadresultDataFromFile(resultFileSize);
	
	char choice,adminChoice,voterChoice;
	int poChoice;
	string userName, Psw;
	int check=0;
	string cnic;

	bool startVoting=false;
	bool anounceResult=false;
	
	cout << BG_WHITE << BLACK << "\t\t\t Election Management System \t\t\t"<<RESET << endl;
	do {
		cout << "\n\t\t\t\t"  << BG_WHITE << BLACK << " Menu "<<RESET << endl;
		cout << "\t\t\t\t------" << endl;
		cout<<"======================================"<<endl;
		cout << "1.Election Commission Login" << endl;
		cout << "2.Presiding Officer Login" << endl;
		cout << "3.Voter Login" << endl;
		if(anounceResult){
			cout << "4.View Result of Election" << endl;
		}
		cout << "5.Exit" << endl;
		cout<<"======================================"<<endl;
		cout << "Enter you choice:";
		cin >> choice;
		cout<<"======================================"<<endl;
		switch (choice) {
		case '1': {
			if(!anounceResult){
				cout << "\n....Election Commission Login...\n" << endl;
				cin.ignore();
				cout << "Enter Your Username: ";
				getline(cin, userName);
				cout << "Enter Your Password: ";
				getline(cin, Psw);
				l = ec;
				if (l->login(userName,Psw)) {
						cout << BG_BLACK  << GREEN << " *****Election Commission Login Successfully.***** " << RESET << endl;
					
					do {
						
						cout << "\n\t\t\t\t" << BG_WHITE << BLACK << " Election Commission Menu "<<RESET << endl;
						cout << "\t\t\t\t---------------------------" << endl;
						cout<<"======================================"<<endl;
						cout << "1. Add PO" << endl;
						cout << "2. Update PO" << endl;
						cout << "3. Delete PO" << endl;
						cout << "4. View PO" << endl;
						cout << "5. Start Polling" << endl;
						cout << "6. Anounce Result" << endl;
						cout << "7. Exit Program" << endl;
						cout<<"======================================"<<endl;
						cout << "Enter your choice: ";
						cin >> adminChoice;
						cout<<"======================================"<<endl;
						switch (adminChoice) {
						case '1':
							if(!startVoting){
								po=ec->addPo(po,poFileSize);
							}else{
								cout << BG_WHITE << RED << " !!!Polling Time is Started.!!! " << RESET << endl;
							}
							break;
						case '2':
							if(!startVoting){
								ec->updatePo(po,poFileSize);
								ec->writePoDataToFile(po,poFileSize);
							}else{
								cout << BG_WHITE << RED << " !!!Polling Time is Started.!!! " << RESET << endl;
							}
						
							break;
						case '3':
							if(!startVoting){
								cout<<"Enter the CNIC of PO You want to delete: ";
								cin>>cnic;
								int poTodelete;
								poTodelete=ec->getDeletingPoIndex(po,poFileSize,cnic);
								if(poTodelete != -1){
									po=ec->deletePo(po,poFileSize,result,resultFileSize,candidate,candidateFileSize,voter,voterFileSize,poTodelete);
									ec->writePoDataToFile(po,poFileSize);
									candidateFileSize=findFileSize("candidate.txt");
									voterFileSize=findFileSize("voter.txt");
									resultFileSize=findFileSize("result.txt");
									candidate=candidate->loadCandidateDataFromFile(candidateFileSize);
									voter=voter->loadVoterDataFromFile(voterFileSize);
									result=result->loadresultDataFromFile(resultFileSize);
								
								}else{
									cout << BG_WHITE << RED << " !!!Presiding officer with this CNIC does not Exists.!!! " << RESET << endl;
								}
							}else{
								cout << BG_WHITE << RED << " !!!Polling Time is Started.!!! " << RESET << endl;
							}
						
							break;
						case '4':
							cout<<endl;
							ec->viewPo(po,poFileSize);
							cout<<endl;
							break;
						case '5':
								if(startVoting==false){
									startVoting=true;
									cout << YELLOW <<"Voters Can Cast Vote Now!"<< RESET <<endl;
									
								}else{
									cout << BG_WHITE << RED << " !!!Voting is Already  Started.!!! " << RESET << endl;
								}
							break;
						case '6':
								
								
								if(startVoting == true){
									anounceResult=true;
									startVoting=false;
									ec->showResult(po,poFileSize,result,resultFileSize,candidate,candidateFileSize);
									adminChoice='7';
								}else{
									cout << BG_WHITE << RED << " !!!Voting is Not Start Yet.!!! " << RESET << endl;
								}
								
							break;
						case '7':
							cout << "Exiting program..." << endl;
							break;
						default:
							cout << BG_WHITE << RED << " !!!Invalid choice. Please try again(ECMenu).!!! " << RESET << endl;
							break;
						}
					} while (adminChoice != '7');
				}else {
					cout << BG_WHITE << RED << " !!!Wrong Username or Password.!!! " << RESET << endl;
				}
			}
			else {
				cout << BG_WHITE << RED << " !!!Result is Announced(You cannot Login).!!! " << RESET << endl;
			}

			break;
		}
		case '2': 
				if(!startVoting && !anounceResult){
						if(poFileSize !=0){
						cout << "\n...Presiding Officer  Login...\n" << endl;
						cout << "Enter Your Username: ";
						cin >> userName;
						cout << "Enter Your Password: ";
						cin >> Psw;
						int c=0;
						
						for(int i=0;i<poFileSize;i++){
							if(po[i].getUsername()==userName ){
								l=&po[i];
								c++;
								//cout<<"yes find"<<endl;
								loggedPo=&po[i];
								break;
							}
						}
						if(c==0){
							cout << BG_WHITE << RED << " !!!Wrong Username or Password.!!! " << RESET << endl;
							break;
						}
						if(l->login(userName,Psw) && c==1){
							cout << BG_BLACK  << GREEN << " *****Presiding Officer Login Successfully.***** " << RESET << endl;
							do{
								cout << "\n\t\t\t\t" << BG_WHITE << BLACK << " PO Menu "<<RESET << endl;
								cout << "\t\t\t\t-------" << endl;
								cout<<"======================================"<<endl;
								cout << "1.Add Candidate" << endl;
								cout << "2.Add Voter" << endl;
								cout << "3.View Candidate-List" << endl;
								cout << "4.View Voter-List" << endl;
								cout << "5.Update Candidate Info" << endl;
								cout << "6.Update Voter Info" << endl;
								cout << "7.Delete Candidate" << endl;
								cout << "8.Delete Voter" << endl;
								cout << "9.Change Password" << endl;
								cout << "10. Exit" << endl;
								cout<<"======================================"<<endl;
						
								cout<<"Enter your Choice: ";
								cin>>poChoice;
								cout<<"======================================"<<endl;
								
							
								switch(poChoice){
									case 1:
										cout<<"Enter the Details of Candidate: "<<endl;
										candidate=loggedPo->addCandidates(candidate,candidateFileSize);
										loggedPo->candidateDataToResult(candidate,candidateFileSize,voter,voterFileSize);
										resultFileSize++;
										result=result->loadresultDataFromFile(resultFileSize);
										break;
									case 2:
										cout<<"Enter the Details of Voter: "<<endl;
										voter=loggedPo->addVoter(voter,voterFileSize,result,resultFileSize);
										result->writeResult(result,resultFileSize);
										break;
									case 3:
										cout<<endl;
										loggedPo->viewCandidates(candidate,candidateFileSize);
										cout<<endl;
										break;
									case 4:
										cout<<endl;
										loggedPo->viewVoter(voter,voterFileSize);
										cout<<endl;
										break;
									case 5:
										loggedPo->updateCandidate(candidate,candidateFileSize);
										loggedPo->writeCandidateDataToFile(candidate,candidateFileSize);
										break;
									case 6:
										loggedPo->updateVoter(voter,voterFileSize);
										loggedPo->writeVoterDataToFile(voter,voterFileSize);
										break;
									case 7:
										
										cout<<"Enter the CNIC of Candidate You want to delete: ";
										cin>>cnic;
										int candTodelete;
										candTodelete=loggedPo->getDeletingCandidateIndex(candidate,candidateFileSize,cnic);
										if(candTodelete != -1){
											candidate=loggedPo->deleteCandidate(candidate,candidateFileSize,result,resultFileSize,candTodelete);
											loggedPo->writeCandidateDataToFile(candidate,candidateFileSize);
											result=result->loadresultDataFromFile(resultFileSize);
										}else{
											cout << BG_WHITE << RED << " !!!Candidate with this CNIC does not Exists in Your Region.!!! " << RESET << endl;
										}
										break;
									case 8:
										voter=loggedPo->deleteVoter(voter,voterFileSize,result,resultFileSize);
										loggedPo->writeVoterDataToFile(voter,voterFileSize);
										result->writeResult(result,resultFileSize);
										break;
									case 9:
										po=loggedPo->changePassword(po,poFileSize);
										break;
									case 10:
									
										cout<<"Exiting..."<<endl;
										
										break;
									default:
										cout << BG_WHITE << RED << " !!!Invalid Number.!!! " << RESET << endl;
										break;
								}
							}while(poChoice !=10);
						}else{
							cout << BG_WHITE << RED << " !!!Wrong Username or Password.!!! " << RESET << endl;
						}
					}else{
						cout << BG_WHITE << RED << " !!!There is no Presiding officer.!!! " << RESET << endl;
					}
				
				}else{
					cout << BG_WHITE << RED << " !!!Sorry!(You cannot LogIn Now).!!! " << RESET << endl;
				}
		
			break;
		
		case '3':
				if(startVoting){
						if(voterFileSize != 0){
						cout << "\n...Voter Login..." << endl;
						check=0;
						cout<<"Enter Your CNIC(without-Dashes): ";
						cin>>cnic;
						
						for(int i=0;i<voterFileSize;i++){
							if(voter[i].getCnic()==cnic ){
								check++;
								loggedVoter=&voter[i];
								
								break;
							}
						}
						if(check != 0 && loggedVoter->getHasVoted()==0){
							do{
								cout <<"\t\t\t\t" << BG_WHITE << BLACK << " Voter Menu "<<RESET << endl;
								 cout << "\t\t\t\t---------" << endl;
								cout<<"======================================"<<endl;
								cout << "1.Veiw Candidate" << endl;
								cout << "2.Cast Vote" << endl;
							
								cout << "3. Exit" << endl;
								cout<<"======================================"<<endl;
								
								cout<<"Enter your Choice: ";
								cin>>voterChoice;
								cout<<"======================================"<<endl;
								switch(voterChoice){
									case '1':
										cout<<endl;
										loggedVoter->viewCandidates(candidate,candidateFileSize);
										cout<<endl;
										break;
									case '2':
										loggedVoter->castVote(candidate,candidateFileSize,result,resultFileSize);
										loggedVoter->writeVoterData(voter,voterFileSize);
										result->writeResult(result,resultFileSize);
										break;
									case '3':
										
										cout<<"Exiting..."<<endl;
										
										break;
									default:
										cout << BG_WHITE << RED << " !!!Invalid Number.!!! " << RESET << endl;
										break;
								}
							}while(voterChoice != '3');
						}else{
							cout << BG_WHITE << RED << " !!!You are not registered./Already Cast Vote.!!! " << RESET << endl;
						}
					}else{
						cout << BG_WHITE << RED << " !!!There is no Voter.!!! " << RESET << endl;
					}
				}else{
					cout << BG_WHITE << RED << " !!!Sorry,Voting is not Yet Started OR Finished.!!! " << RESET << endl;
				}
				
			
			break;
		case '4':
			if(anounceResult){
				ec->showResult(po,poFileSize,result,resultFileSize,candidate,candidateFileSize);
				
				char c;
				cout<<"Do You want to close Election Results(Y/n):";
				cin>>c;
				if(c=='Y' || c=='y'){
					cout<<"Enter Username: ";
					cin>>userName;
					cout<<"Enter Password: ";
					cin>>Psw;
					if(userName=="admin" && Psw=="1234"){
						anounceResult=false;
					}
				}
				
			}else{
				cout << BG_WHITE << RED << " !!!Invalid Choice.!!! " << RESET << endl;
			}
			
			break;
		case '5':
			cout << "Exiting....." << endl;
			break;
		default:
			cout << BG_WHITE << RED << " !!!Invalid Choice.!!! " << RESET << endl;
			break;
		}
	} while (choice != '5');
	
	
	
	
	delete [] voter;
	delete [] candidate;
	delete [] po;
	delete [] result;
	delete ec;
	
	
	return 0;
}

