#include <cstdlib>
#include <iostream>
#include <fstream> 
#include <sstream> 
#include <string>
#include <vector>

using namespace std;

class Mypoint;
class Myline;
class Mytriangle;
class Mymaptriangle;
class Mypar;
class Mypoints;
class Mysphere;

string inttostr(const int &n); 
string floattostr(const float &n) ;
bool getstrline(string &str,string &x);
float strtofloat(const std::string &n) ;
int strtoint(const std::string &n) ;
bool line_line_y(Myline l1,Myline l2);
bool line_line_x(Myline l1,Myline l2);
bool line_line_z(Myline l1,Myline l2);
bool line_sphere_y(Myline l,Mysphere sp,Myline pl);
bool tr_par_x(Mytriangle tr,Mypar par);
bool tr_par_z(Mytriangle tr,Mypar par);
class Mypoint{
public:
	float x;
	float y;
	float z;      
	int loadfromstr(string s);
	int show();
	void myput(ofstream &f){
		f<<"v "<<x<<" "<<y<<" "<<z<<" \n";
	};
};

class Myline{
public: 
	Mypoint points[2];
};

class Mypar{
public:
	Mypoint points[4];
};

class Mytriangle{
public:
	Mypoint points[3];
	bool in_sphere_y(Mysphere sp);
	bool sphere_in_y(Mysphere sp,Myline pl);
	bool point_in_triangle_y(Mypoint p);
	bool point_in_triangle_x(Mypoint p);
	bool point_in_triangle_z(Mypoint p);

	bool line_in_triangle_y(Myline l);
	bool line_in_triangle_x(Myline l);
	bool line_in_triangle_z(Myline l);
	bool line_in_triangle(Myline l);
	bool tr_in_tr_y(Mytriangle tr);
	bool tr_in_tr_x(Mytriangle tr);
	bool tr_in_tr_z(Mytriangle tr);
};

class Mymaptriangle{
public:
	int pointnums[3];
	void loadfromstr(string s){
		int i;
		string ss;
		i=0;
		while((s[i]!=' ')&&(i<s.length())){
			i++;
		}
		while((s[i]==' ')&&(i<s.length())){
			i++;
		}
		ss="";
		while((s[i]!=' ')&&(i<s.length())){
			ss+=s[i++];
		}
		pointnums[0]=strtoint(ss);
		while((s[i]==' ')&&(i<s.length())){
			i++;
		}
		ss="";
		while((s[i]!=' ')&&(i<s.length())){
			ss+=s[i++];
		}
		pointnums[1]=strtoint(ss);

		while((s[i]==' ')&&(i<s.length())){
			i++;
		}
		ss="";
		while((s[i]!=' ')&&(i<s.length())){
			ss+=s[i++];
		}
		pointnums[2]=strtoint(ss);
	};

	void myput(ofstream &f){
		f<<"MT ";
		for(int i=0;i<3;i++){
			f<<pointnums[i]<<" ";
		}
		f<<"\n";
	};

};
class Mypoints{
public:
	vector <Mypoint> p;
	int mydel();
	int show();
	int loadfromfile(ifstream &f){
		bool b=true;
		Mypoint point;
		string s;
		size_t found = s.find("endMypoints ");
		if (found!=std::string::npos){b=false;}
		while((b)&&(getline(f,s))){
				found = s.find("endMypoints ");
				if (found!=std::string::npos){
					b=false;
				}
				else{
					point.loadfromstr(s);
					p.push_back(point);
				}
		}
		return f.tellg();
	};
	void myput(ofstream &f){
		f<<"Mypoints \n";
		for(int i=0;i<p.size();i++)p[i].myput(f);
		f<<"endMypoints \n";
	}; 
};

class Mysphere{
public:
	float radius;
	Mypoint oxyz;
};


class Mysquare{
public:
	int fff[3];
	int loadfromstr(string s);
	int show();
	void myput(ofstream &f){
		f<<"f "<<fff[0]<<" "<<fff[1]<<" "<<fff[2]<<" \n";
	}; 
	
};

class Myforma{
public:
	vector <Mysquare> ff;
	void mydel();
	int show();
	void myput(ofstream &f){
		f<<"Myforma \n";
		for(int i=0;i<ff.size();i++){
			ff[i].myput(f);
		}
		f<<"endMyforma \n";
	}; 
int loadfromfile(ifstream &f){
		bool b=true;
		int restell;
		Mysquare point;
		string s;
		size_t found = s.find("endMyforma ");
		if (found!=std::string::npos){b=false;}
		while((b)&&(getline(f,s))){
				found = s.find("endMyforma ");
				if (found!=std::string::npos){
					b=false;
				}
				else{
					point.loadfromstr(s);
					ff.push_back(point);
				}
		}
		return f.tellg();
	};
	
};

class Myplayer{
public:
	bool ingame;
	float Radius,Height;
	Mypoint point;
	int loadfromstr(string s);
};

class Mymapcollisobj{
public:
	int collistr[2];
	void myput(ofstream &f){
		f<<"MC "<<collistr[0]<<" "<<collistr[1]<<" \n";
	};
	void loadfromstr(string s){
		int i;
		string ss;
		i=0;
		while((s[i]!=' ')&&(i<s.length())){
			i++;
		}
		while((s[i]==' ')&&(i<s.length())){
			i++;
		}
		ss="";
		while((s[i]!=' ')&&(i<s.length())){
			ss+=s[i++];
		}
		collistr[0]=strtoint(ss);
		while((s[i]==' ')&&(i<s.length())){
			i++;
		}
		ss="";
		while((s[i]!=' ')&&(i<s.length())){
			ss+=s[i++];
		}
		collistr[1]=strtoint(ss);

	};

};

class Mycube{
public:
	Mypoint p[8];
	Mymaptriangle triang[16];//12
	vector <Mymapcollisobj> collisobjs;
	void show();
	bool pl_in_cube(Myplayer mp);
	void myput(ofstream &f){
		f<<"Mycube \n";
		for(int i=0;i<8;i++){p[i].myput(f);}
		for(int i=0;i<12;i++){triang[i].myput(f);}
		for(int i=0;i<collisobjs.size();i++){
			collisobjs[i].myput(f);
		}
		f<<"endMycube \n";
	}; 
int loadfromfile(ifstream &f){
		bool b=true;
		Mysquare point;
		string s;
		Mymapcollisobj c;
		collisobjs.clear();
		for(int i=0;i<8;i++){
			getline(f,s);
			p[i].loadfromstr(s);
		}
		for(int i=0;i<12;i++){
			getline(f,s);
			triang[i].loadfromstr(s);
		}
		size_t found = s.find("endMycube ");
		if (found!=std::string::npos){b=false;}
		while((b)&&(getline(f,s))){
			found = s.find("endMycube ");
				if (found!=std::string::npos){
					b=false;
				}
			
			else{
				//getline(f,s);
				c.loadfromstr(s);
				collisobjs.push_back(c);
			}
		}
		return f.tellg();
	};

};

class Myobj{
public:
	int num;
	Mypoints v;
	Myforma f;
	//            int loadfromfile(string filename,Mypoint xyz,Mypoint scale);
	int loadfromstr(string str);
	void mydel(){
		v.p.clear();
		f.ff.clear();
	};
	void show();
	//int in_obj(Mypoint mp,int xpp);
	//int in_obj_cyl(Myplayer mp);
	//int in_obj_cube(Mycube* mp);
	bool in_triangle(int num,Myplayer mp,Myline pl,Mypar par);
	void myput(ofstream &ff){
		ff<<"Myobj \n";
		v.myput(ff);
		f.myput(ff);
		ff<<"endMyobj \n";
	};
	int loadfromfile(ifstream &ff){
		bool b=true;
		string s;
		size_t found = s.find("endMyobj ");
		if (found!=std::string::npos){b=false;}
		while((b)&&(getline(ff,s))){			
				found = s.find("endMyobj ");
				if (found!=std::string::npos){
					b=false;
				}
				found = s.find("Mypoints ");
				if (found!=std::string::npos){
					v.loadfromfile(ff);
				}
				found = s.find("Myforma ");
				if (found!=std::string::npos){
					f.loadfromfile(ff);
				}
			}

		return ff.tellg();
	};
};

class Mygamemap{
public:
	Mypoint eachcube,begp,endp;
	vector <Mycube> ps;	
	int getx(float x);
	int getz(float z);
	int getnum(int i,int j);
	void init(Mypoint p,Mypoint len,Mypoint c);	
	void clear(){
		eachcube.x=0;
		eachcube.y=0;
		eachcube.z=0;
		for(int i=0;i<ps.size();i++)ps[i].collisobjs.clear();
		ps.clear();
	}
	void myput(ofstream &f){
		f<<"Mygamemap \n";
		eachcube.myput(f);
		begp.myput(f);
		endp.myput(f);
		for(int i=0;i<ps.size();i++){
			ps[i].myput(f);
		}
		f<<"endMygamemap \n";
	};
	
	int loadfromfile(ifstream &ff){
		bool b=true;
		string s;
		Mycube p;
				getline(ff,s);
				eachcube.loadfromstr(s);
				getline(ff,s);
				begp.loadfromstr(s);
				getline(ff,s);
				endp.loadfromstr(s);
		size_t found = s.find("endMygamemap ");
		if (found!=std::string::npos){b=false;}
		while((b)&&(getline(ff,s))){			
				found = s.find("endMygamemap ");
				if (found!=std::string::npos){
					b=false;
				}
				else{
				found = s.find("Mycube ");
				if (found!=std::string::npos){
				
					//getline(ff,s);
					p.collisobjs.clear();
					p.loadfromfile(ff);
					if(ps.size()>108){
					ps.push_back(p);
					}else{
					ps.push_back(p);
					}
				}
				}
		}

		return ff.tellg();
	};
	void show();
};


class Myobjs{
public:
	vector <Myobj> objs;
	Mygamemap mygamemap;
	void find_collobj(int numps,int numobj);
	void creategamemap(int num);
	void clear(){
		for(int i=0;i<objs.size();i++){
			objs[i].f.ff.clear();
			objs[i].v.p.clear();
		}
		objs.clear();
		mygamemap.clear();
	};
	void myput(ofstream &f){
		f<<"Myobjs \n";
		for(int i=0;i<objs.size();i++){
			objs[i].myput(f);
		}
		mygamemap.myput(f);
		f<<"endMyobjs \n";
	};
	int loadfromfile(ifstream &f){
		bool b=true;
		string s;
		Myobj p;
		clear();
				
		size_t found; /*= s.find("endMyobjs ");
		if (found!=std::string::npos){b=false;}*/
		while((b)&&(getline(f,s))){
				found = s.find("endMyobjs ");
				if (found!=std::string::npos){
					b=false;
				}
				else{
				found = s.find("Myobj ");
				if (found!=std::string::npos){
					//getline(ff,s);
					p.mydel();
					p.loadfromfile(f);
					objs.push_back(p);
				}			
				/*found = s.find("Mygamemap ");
				if (found!=std::string::npos){
					//getline(ff,s);
				mygamemap.loadfromfile(f);
				}
				*/
				}		
		}

		return f.tellg();
	} 
};

