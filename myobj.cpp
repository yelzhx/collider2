#include "stdafx.h"

float minf(float f1,float f2){
	float min;
	if(f1<f2){min=f1;}
	else{min=f2;}
	return min;
}
float maxf(float f1,float f2){
	float max;
	if(f1>f2){max=f1;}
	else{max=f2;}
	return max;
}

string inttostr(const int &n) {
	std::stringstream str;
	str << n;
	string ret;
	str >> ret;
	return ret;
};


string floattostr(const float &n) {
	std::stringstream str;
	str << n;
	string ret;
	str >> ret;
	return ret;
};

float strtofloat(const std::string &n) {
	std::stringstream str;
	str << n;
	float ret;
	str >> ret;
	return ret;
};

int strtoint(const std::string &n) {
	std::stringstream str;
	str << n;
	int ret;
	str >> ret;
	return ret;
};

bool getstrline(string &str,string &x){
	bool res=false;
	bool b=true;
	int i=0;
	x="";
	while(b){

		if(i>=str.length()){b=false;}
		else{
			if(str[i]=='\n'){
				x=str.substr(0,i);
				str=str.substr(i+1,str.length()-1);
				res=true;
				b=false;
			}
			i++;}
	}
	return res;     
}
bool in_theline(float x,float z,float x0,float z0,float x1,float z1){
	bool b=false;
	float maxx,minx,maxz,minz;
	if(x0>x1){maxx=x0;minx=x1;}
	else{maxx=x1;minx=x0;}
	if(z0>z1){maxz=z0;minz=z1;}
	else{maxz=z1;minz=z0;}
	if((minx!=maxx)&&(minz!=maxz)){
		if((x>minx)&&(x<maxx)&&(z>minz)&&(z<maxz))b=true;
	}
	else if(minx!=maxx){
		if((x>minx)&&(x<maxx))b=true;
	}
	else {
		if((z>minz)&&(z<maxz))b=true;
	}
	return b;
};


bool vertcross(float y,float h,float y0,float y1){
	bool b=false;
	float yy0,yy1,miny,maxy;
	yy0=y-h/2;
	yy1=y+h/2;
	if(y0<=y1){
		miny=y0;
		maxy=y1;
	}
	else{
		miny=y1;
		maxy=y0;
	}
	if((yy0>=miny)&&(yy0<=maxy))b=true;
	if((yy1>=miny)&&(yy1<=maxy))b=true;
	if((yy1>=miny)&&(yy0<=miny))b=true;
	if((yy1>=maxy)&&(yy0<=maxy))b=true;
	return b;
}

bool myintersecttop(Myline p1,Myline p2){
	bool bl=false;
	float x,z,OXX,OYY,OZZ,XX,YY,ZZ;
	XX=p2.points[1].x-p2.points[0].x;
	ZZ=p2.points[1].z-p2.points[0].z;
	YY=p2.points[1].y-p2.points[0].y;
	OXX=p1.points[1].x-p1.points[0].x;
	OZZ=p1.points[1].z-p1.points[0].z;
	OYY=p1.points[1].y-p1.points[0].y;
	if((OXX*ZZ-XX*OZZ)!=0){
		z=(p1.points[0].z*OXX*ZZ+p2.points[0].x*ZZ*OZZ-p1.points[0].x*OZZ*ZZ-p2.points[0].z*XX*OZZ)/(OXX*ZZ-XX*OZZ);
		if(ZZ!=0){
			x=(z*XX-p2.points[0].z*XX+p2.points[0].x*ZZ)/ZZ;
			if((in_theline(x,z,p1.points[0].x,p1.points[0].z,p1.points[1].x,p1.points[1].z))
				&&(in_theline(x,z,p2.points[0].x,p2.points[0].z,p2.points[1].x,p2.points[1].z))){
					bl=true;
			}
			else{

			}
		}
	}
	return bl;

}

bool line_line_y(Myline l1,Myline l2){
	bool bl=false;
	float x,y,z,OXX,OYY,OZZ,XX,YY,ZZ;
	XX=l2.points[1].x-l2.points[0].x;
	ZZ=l2.points[1].z-l2.points[0].z;
	YY=l2.points[1].y-l2.points[0].y;
	OXX=l1.points[1].x-l1.points[0].x;
	OZZ=l1.points[1].z-l1.points[0].z;
	OYY=l1.points[1].y-l1.points[0].y;
	if((OXX*ZZ-XX*OZZ)!=0){
		z=(l1.points[0].z*OXX*ZZ+l2.points[0].x*ZZ*OZZ-l1.points[0].x*OZZ*ZZ-l2.points[0].z*XX*OZZ)/(OXX*ZZ-XX*OZZ);
		if(ZZ!=0){
			x=(z*XX-l2.points[0].z*XX+l2.points[0].x*ZZ)/ZZ;
			if((in_theline(x,z,l1.points[0].x,l1.points[0].z,l1.points[1].x,l1.points[1].z))
				&&(in_theline(x,z,l2.points[0].x,l2.points[0].z,l2.points[1].x,l2.points[1].z))){
					bl=true;
			}
			else{

			}
		}
	}
	if(!bl){
		if((OZZ*XX-ZZ*OXX)!=0){
			x=(l1.points[0].x*OZZ*XX+l2.points[0].z*XX*OXX-l1.points[0].z*OXX*XX-l2.points[0].x*ZZ*OXX)/(OZZ*XX-ZZ*OXX);
			if(XX!=0){
				z=(x*ZZ-l2.points[0].x*ZZ+l2.points[0].z*XX)/XX;
				if((in_theline(x,z,l1.points[0].x,l1.points[0].z,l1.points[1].x,l1.points[1].z))
					&&(in_theline(x,z,l2.points[0].x,l2.points[0].z,l2.points[1].x,l2.points[1].z))){
						bl=true;

				}
				else{

				}
			}
		}
	}
	return bl;
};


bool line_line_x(Myline l1,Myline l2){
	bool bl=false;
	float x,y,z,OXX,OYY,OZZ,XX,YY,ZZ;
	XX=l2.points[1].x-l2.points[0].x;
	ZZ=l2.points[1].z-l2.points[0].z;
	YY=l2.points[1].y-l2.points[0].y;
	OXX=l1.points[1].x-l1.points[0].x;
	OZZ=l1.points[1].z-l1.points[0].z;
	OYY=l1.points[1].y-l1.points[0].y;
	if((OZZ*YY-ZZ*OYY)!=0){
		y=(l1.points[0].y*OZZ*YY+l2.points[0].z*YY*OYY-l1.points[0].z*OYY*YY-l2.points[0].y*ZZ*OYY)/(OZZ*YY-ZZ*OYY);
		if(YY!=0){
			z=(y*ZZ-l2.points[0].y*ZZ+l2.points[0].z*YY)/YY;
			if((in_theline(z,y,l1.points[0].z,l1.points[0].y,l1.points[1].z,l1.points[1].y))
				&&(in_theline(z,y,l2.points[0].z,l2.points[0].y,l2.points[1].z,l2.points[1].y))){
					bl=true;

			}
			else{

			}
		}
	}
	if(!bl){
		if((ZZ*OYY-OZZ*YY)!=0){
			y=(l2.points[0].y*ZZ*OYY+l1.points[0].z*OYY*YY-l2.points[0].z*YY*OYY-l1.points[0].y*OZZ*YY)/(ZZ*OYY-OZZ*YY);
			if(OYY!=0){
				z=(y*OZZ-l1.points[0].y*OZZ+l1.points[0].z*OYY)/OYY;
				if((in_theline(z,y,l1.points[0].z,l1.points[0].y,l1.points[1].z,l1.points[1].y))
					&&(in_theline(z,y,l2.points[0].z,l2.points[0].y,l2.points[1].z,l2.points[1].y))){
						bl=true;

				}
				else{

				}
			}
		}
	}
	return bl;
};


bool line_line_z(Myline l1,Myline l2){
	bool bl=false;
	float x,y,z,OXX,OYY,OZZ,XX,YY,ZZ;
	XX=l2.points[1].x-l2.points[0].x;
	ZZ=l2.points[1].z-l2.points[0].z;
	YY=l2.points[1].y-l2.points[0].y;
	OXX=l1.points[1].x-l1.points[0].x;
	OZZ=l1.points[1].z-l1.points[0].z;
	OYY=l1.points[1].y-l1.points[0].y;
	if((OXX*YY-XX*OYY)!=0){
		y=(l1.points[0].y*OXX*YY+l2.points[0].x*YY*OYY-l1.points[0].x*OYY*YY-l2.points[0].y*XX*OYY)/(OXX*YY-XX*OYY);
		if(YY!=0){
			x=(y*XX-l2.points[0].y*XX+l2.points[0].x*YY)/YY;
			if((in_theline(x,y,l1.points[0].x,l1.points[0].y,l1.points[1].x,l1.points[1].y))
				&&(in_theline(x,y,l2.points[0].x,l2.points[0].y,l2.points[1].x,l2.points[1].y))){
					bl=true;

			}
			else{

			}
		}
	}
	if(!bl){
		if((XX*OYY-OXX*YY)!=0){
			y=(l2.points[0].y*XX*OYY+l1.points[0].x*OYY*YY-l2.points[0].x*YY*OYY-l1.points[0].y*OXX*YY)/(XX*OYY-OXX*YY);
			if(OYY!=0){
				x=(y*OXX-l1.points[0].y*OXX+l1.points[0].x*OYY)/OYY;
				if((in_theline(x,y,l1.points[0].x,l1.points[0].y,l1.points[1].x,l1.points[1].y))
					&&(in_theline(x,y,l2.points[0].x,l2.points[0].y,l2.points[1].x,l2.points[1].y))){
						bl=true;

				}
				else{

				}
			}
		}
	}
	return bl;
};

bool line_sphere_y(Myline l,Mysphere sp,Myline pl){
	bool bl;
	float x0,x1,z0,z1,y0,y1,A,B,C,D,E,XX,ZZ,XXX,ZZZ,X1,Z1,X2,Z2,Y1,Y2,R,a,b,miny,maxy;
	bl=false;
	x0=l.points[0].x;
	z0=l.points[0].z;
	y0=l.points[0].y;
	x1=l.points[1].x;
	z1=l.points[1].z;
	y1=l.points[1].y;
	R=sp.radius;
	if(z1!=z0){
		//----------
		A=(z1-z0);
		B=(x0-x1);

		C=(z0*x1-x0*z1);
		a=sqrt(A*A+B*B);

		if(a!=0){
			D=0;
			D=(A*sp.oxyz.x+B*sp.oxyz.z+C)/a;
			if(D<0)D=D*(-1);
			if(D<=R){					
				a=sp.oxyz.x;
				b=sp.oxyz.z;
				XX=(x1-x0);
				ZZ=(z1-z0);
				ZZZ=ZZ*ZZ;
				XXX=XX*XX;
				E=x0*ZZ-z0*XX-a*ZZ;

				A=XXX+ZZZ;
				B=(2*E*XX-(ZZ*ZZ)*2*b);
				C=E*E-(ZZ*ZZ)*R*R+(ZZ*ZZ)*b*b;
				D=B*B-4*A*C;
				if(D>=0){
					Z1=(-B+sqrt(D))/(2*A);
					Z2=(-B-sqrt(D))/(2*A);
					X1=sqrt(R*R-(Z1-b)*(Z1-b))+a;
					X2=sqrt(R*R-(Z2-b)*(Z2-b))+a;
					if((X1!=X2)||(Z1!=Z2)){
						if(in_theline(X1,Z1,x0,z0,x1,z1)){
							//y=y1+(y2-y1)*(x-x1)/(x2-x1)
							//	if(()&&())
							if(y0<y1){
								miny=y0;
								maxy=y1;
							}
							else{
								miny=y1;
								maxy=y0;
							}
							if((miny<pl.points[0].y)&&(maxy>pl.points[1].y)){
							bl=true;
							}
							else{
							Y1=y0+(y1-y0)*(Z1-z0)/(z1-z0);
							if((Y1>pl.points[0].y)&&(Y1<pl.points[1].y)){
								bl=true;
							}
							}
						}
						if(!bl){
							if(in_theline(X2,Z2,x0,z0,x1,z1)){
								//y=y1+(y2-y1)*(x-x1)/(x2-x1)
							if(y0<y1){
								miny=y0;
								maxy=y1;
							}
							else{
								miny=y1;
								maxy=y0;
							}
							if((miny<pl.points[0].y)&&(maxy>pl.points[1].y)){
								bl=true;
								}
								else{
								Y2=y0+(y1-y0)*(Z2-z0)/(z1-z0);
								if((Y2>pl.points[0].y)&&(Y2<pl.points[1].y)){
									bl=true;
								}
								}
							}
						}
					}
				}
			}
		}
	}
	else{
		//------------------
		A=(x1-x0);
		B=(z0-z1);

		C=(x0*z1-z0*x1);
		a=sqrt(A*A+B*B);

		if(a!=0){
			D=0;
			D=(A*sp.oxyz.z+B*sp.oxyz.x+C)/a;
			if(D<0)D=D*(-1);
			if(D<=R){					
				a=sp.oxyz.z;
				b=sp.oxyz.x;
				XX=(x1-x0);
				ZZ=(z1-z0);
				ZZZ=ZZ*ZZ;
				XXX=XX*XX;
				E=z0*XX-x0*ZZ-a*XX;

				A=XXX+ZZZ;
				B=(2*E*ZZ-(XX*XX)*2*b);
				C=E*E-(XX*XX)*R*R+(XX*XX)*b*b;
				D=B*B-4*A*C;
				if(D>=0){
					X1=(-B+sqrt(D))/(2*A);
					X2=(-B-sqrt(D))/(2*A);
					Z1=sqrt(R*R-(X1-b)*(X1-b))+a;
					Z2=sqrt(R*R-(X2-b)*(X2-b))+a;
					if((X1!=X2)||(Z1!=Z2)){
						if(in_theline(X1,Z1,x0,z0,x1,z1)){
							
							if(y0<y1){
								miny=y0;
								maxy=y1;
							}
							else{
								miny=y1;
								maxy=y0;
							}
							if((miny<pl.points[0].y)&&(maxy>pl.points[1].y)){
								bl=true;
							}
							else{
								Y1=y0+(y1-y0)*(X1-x0)/(x1-x0);
								if((Y1>pl.points[0].y)&&(Y1<pl.points[1].y)){
									bl=true;
								}
							}

						}
						if(!bl){
							if(in_theline(X2,Z2,x0,z0,x1,z1)){
							
							if(y0<y1){
								miny=y0;
								maxy=y1;
							}
							else{
								miny=y1;
								maxy=y0;
							}
							if((miny<pl.points[0].y)&&(maxy>pl.points[1].y)){
									bl=true;
								}
								else{
									Y2=y0+(y1-y0)*(X2-x0)/(x1-x0);
									if((Y2>pl.points[0].y)&&(Y2<pl.points[1].y)){
										bl=true;
									}
								}

							}
						}
					}}
			}
		}
		//--------------
	}
	//------------------
	return bl;
};

bool tr_par_x(Mytriangle tr,Mypar par){
	bool bb=false;
	int i;
	Mytriangle tr1;
	i=0;
	while((i<3)&&(!bb)){
		
		if(!bb){
			if(i==0){
				tr1.points[0]=par.points[i];
				tr1.points[1]=par.points[i+1];
				tr1.points[2]=par.points[i+2];
				if(tr.tr_in_tr_x(tr1))bb=true;
			}
		}
		if(!bb){
			if(i==2){
				tr1.points[0]=par.points[i];
				tr1.points[1]=par.points[i+1];
				tr1.points[2]=par.points[0];
				if(tr.tr_in_tr_x(tr1))bb=true;
			}}
		i++;
	}

	return bb;
};
bool tr_par_z(Mytriangle tr,Mypar par){
	bool bb=false;
	int i;
	Mytriangle tr1;
	i=0;
	while((i<3)&&(!bb)){
		
		if(!bb){
			if(i==0){
				tr1.points[0]=par.points[i];
				tr1.points[1]=par.points[i+1];
				tr1.points[2]=par.points[i+2];
				if(tr.tr_in_tr_z(tr1))bb=true;
			}
		}
		if(!bb){
			if(i==2){
				tr1.points[0]=par.points[i];
				tr1.points[1]=par.points[i+1];
				tr1.points[2]=par.points[0];
				if(tr.tr_in_tr_z(tr1))bb=true;
			}
		}
		i++;
	}

	return bb;
};


//Mypoint
int Mypoint::loadfromstr(string s){
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
	x=strtofloat(ss);
	while((s[i]==' ')&&(i<s.length())){
		i++;
	}
	ss="";
	while((s[i]!=' ')&&(i<s.length())){
		ss+=s[i++];
	}
	y=strtofloat(ss);

	while((s[i]==' ')&&(i<s.length())){
		i++;
	}
	ss="";
	while((s[i]!=' ')&&(i<s.length())){
		ss+=s[i++];
	}
	z=strtofloat(ss);

	return 0;
};

int Mypoint::show(){
	printf("V %.2f %.2f %.2f\n",x,y,z);
	return 0;
};


// Mypoints
int Mypoints::mydel(){
	p.clear();	
	return 0;
};

int Mypoints::show(){
	int i;
	for(i=0;i<p.size();i++){
		p[i].show();
	}
	return 0;
};

int Mysquare::loadfromstr(string s){
	int i,k,count;
	count=0;
	i=0;
	k=0;
	while ((s[i]!=' ')&&(i<s.length())){
		i++;
	}

	while((s[i]==' ')&&(i<s.length())){
		i++;
	}
	while (i<s.length()){
		if(s[i]==' '){
			k++;
		}
		i++;
	}

	//count=k;
	string ss="";
	string sn="";
	string st="";
	i=0;
	while((s[i]!=' ')&&(i<s.length())){
		i++;
	}
	while((s[i]==' ')&&(i<s.length())){
		i++;
	}
	ss="";
	sn="";
	st="";
	k=0;
	int b;
	b=0;
	while(i<s.length()){
		if(s[i]==' '){

			fff[count++]=strtoint(ss);
			ss="";
			sn="";
			st="";

			b=0;
		}
		else{
			if(s[i]=='/'){b++;}
			else{
				if(b==0){
					ss+=s[i];
				}

				if(b==1){
					st+=s[i];
				}
				if(b==2){
					sn+=s[i];
				}
			}
		}
		i++;
	}


	return 0;
};

int Mysquare::show(){
	int i;
	for(i=0;i<3;i++){
		cout<<fff[i]<<" ";
	}
	cout<<"\n";
	return 0;
};
//Myform
void Myforma::mydel(){
	ff.clear();

};

int Myforma::show(){
	int i;
	for(i=0;i<ff.size();i++){
		ff[i].show();
	}
	return 0;
};

//Myplayer

int Myplayer::loadfromstr(string s){
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
	point.x=strtofloat(ss);
	while((s[i]==' ')&&(i<s.length())){
		i++;
	}
	ss="";
	while((s[i]!=' ')&&(i<s.length())){
		ss+=s[i++];
	}
	point.y=strtofloat(ss);

	while((s[i]==' ')&&(i<s.length())){
		i++;
	}
	ss="";
	while((s[i]!=' ')&&(i<s.length())){
		ss+=s[i++];
	}
	point.z=strtofloat(ss);

	while((s[i]==' ')&&(i<s.length())){
		i++;
	}
	ss="";
	while((s[i]!=' ')&&(i<s.length())){
		ss+=s[i++];
	}
	Radius=strtofloat(ss);
	while((s[i]==' ')&&(i<s.length())){
		i++;
	}
	ss="";
	while((s[i]!=' ')&&(i<s.length())){
		ss+=s[i++];
	}
	Height=strtofloat(ss);

	return 0;
};

//Mycube
void Mycube::show(){
	printf("(%d ",this->collisobjs.size());
	for(int i=0;i<this->collisobjs.size();i++){
		printf(" %d-%d",this->collisobjs[i].collistr[0],this->collisobjs[i].collistr[1]);
	}
	printf(")");
};

bool Mycube::pl_in_cube(Myplayer mp){
	bool b=false,bx=false,bz=false;
	if((mp.point.x>=p[triang[0].pointnums[0]].x)&&(mp.point.x<=p[triang[0].pointnums[1]].x))bx=true;
	if((mp.point.z>=p[triang[2].pointnums[0]].z)&&(mp.point.z<=p[triang[2].pointnums[1]].z))bz=true;
	if(!((bx)&&(bz))){
		if((mp.point.x+mp.Radius/2>=p[triang[0].pointnums[0]].x)&&(mp.point.x+mp.Radius/2<=p[triang[0].pointnums[1]].x))bx=true;
		if((mp.point.z+mp.Radius/2>=p[triang[2].pointnums[0]].z)&&(mp.point.z+mp.Radius/2<=p[triang[2].pointnums[1]].z))bz=true;

		if(!((bx)&&(bz))){
			if((mp.point.x-mp.Radius/2>=p[triang[0].pointnums[0]].x)&&(mp.point.x-mp.Radius/2<=p[triang[0].pointnums[1]].x))bx=true;
			if((mp.point.z-mp.Radius/2>=p[triang[2].pointnums[0]].z)&&(mp.point.z-mp.Radius/2<=p[triang[2].pointnums[1]].z))bz=true;
		}
	}
	b=(bx)&&(bz);
	return b;
};

bool Mytriangle::in_sphere_y(Mysphere sp){
	bool bb=false;
	int i;
	float r;
	for(i=0;(!bb)&&(i<3);i++){
		r=sqrt((sp.oxyz.x-this->points[i].x)*(sp.oxyz.x-this->points[i].x)-(sp.oxyz.z-this->points[i].z)*(sp.oxyz.z-this->points[i].z));
		if(abs(r)<=sp.radius)
		{
			//			bb=true;
		}
	}
	return bb;
};

bool Mytriangle::sphere_in_y(Mysphere sp,Myline pl){
	bool bb=false;
	int i;

	Myline l;
	if(in_sphere_y(sp))bb=true;
	if(!bb){
		if(point_in_triangle_y(sp.oxyz))bb=true;
	}
	if(!bb){
		for(i=0;(!bb)&&(i<3);i++){
			l.points[0]=this->points[i];
			if(i<2){
				l.points[1]=this->points[i+1];
			}
			else{
				l.points[1]=this->points[0];
			}
			if(line_sphere_y(l,sp,pl))
			{
				bb=true;
			}
		}
	}
	return bb;
};

bool Mytriangle::point_in_triangle_y(Mypoint p){
	bool bb=false;
	float a,b,c,e=0;
	a = (points[0].x - p.x) * (points[1].z  - points[0].z) - (points[1].x  - points[0].x) * (points[0].z - p.z);
	b = (points[1].x - p.x) * (points[2].z  - points[1].z) - (points[2].x  - points[1].x) * (points[1].z - p.z);
	c = (points[2].x - p.x) * (points[0].z  - points[2].z) - (points[0].x  - points[2].x) * (points[2].z - p.z);
	if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)){
		bb=true;
	}
	return bb;
};

bool Mytriangle::point_in_triangle_x(Mypoint p){
	bool bb=false;
	float a,b,c,e=0;
	a = (points[0].y - p.y) * (points[1].z  - points[0].z) - (points[1].y  - points[0].y) * (points[0].z - p.z);
	b = (points[1].y - p.y) * (points[2].z  - points[1].z) - (points[2].y  - points[1].y) * (points[1].z - p.z);
	c = (points[2].y - p.y) * (points[0].z  - points[2].z) - (points[0].y  - points[2].y) * (points[2].z - p.z);
	if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)){
		bb=true;
	}
	return bb;
};

bool Mytriangle::point_in_triangle_z(Mypoint p){
	bool bb=false;
	float a,b,c,e=0;
	a = (points[0].x - p.x) * (points[1].y  - points[0].y) - (points[1].x  - points[0].x) * (points[0].y - p.y);
	b = (points[1].x - p.x) * (points[2].y  - points[1].y) - (points[2].x  - points[1].x) * (points[1].y - p.y);
	c = (points[2].x - p.x) * (points[0].y  - points[2].y) - (points[0].x  - points[2].x) * (points[2].y - p.y);
	if ((a >= 0 && b >= 0 && c >= 0) || (a <= e && b <= 0 && c <= 0)){
		bb=true;
	}
	return bb;
};

bool Mytriangle::line_in_triangle_y(Myline l){
	bool bb=false;
	int i;

	Myline l2;
	for(i=0;(!bb)&&(i<2);i++){
		if(point_in_triangle_y(l.points[i]))bb=true;
	}
	if(!bb){
		for(i=0;(!bb)&&(i<3);i++){
			l2.points[0]=this->points[i];
			if(i<2){
				l2.points[1]=this->points[i+1];
			}
			else{
				l2.points[1]=this->points[0];
			}
			if(line_line_y(l,l2)){
				bb=true;
			}
		}
	}


	return bb;
};
bool Mytriangle::line_in_triangle_x(Myline l){
	bool bb=false;
	int i;
	Myline l2;
	for(i=0;(!bb)&&(i<2);i++){
		if(point_in_triangle_x(l.points[i]))bb=true;
	}
	if(!bb){
		for(i=0;(!bb)&&(i<3);i++){
			l2.points[0]=this->points[i];
			if(i<2){
				l2.points[1]=this->points[i+1];
			}
			else{
				l2.points[1]=this->points[0];
			}
			if(line_line_x(l,l2)){
				bb=true;
			}
		}
	}

	return bb;
};

bool Mytriangle::line_in_triangle_z(Myline l){
	bool bb=false;
	int i;
	Myline l2;
	for(i=0;(!bb)&&(i<2);i++){
		if(point_in_triangle_z(l.points[i]))bb=true;
	}

	if(!bb){
		for(i=0;(!bb)&&(i<3);i++){
			l2.points[0]=this->points[i];
			if(i<2){
				l2.points[1]=this->points[i+1];
			}
			else{
				l2.points[1]=this->points[0];
			}
			if(line_line_z(l,l2)){
				bb=true;
			}
		}
	}


	return bb;
};

bool Mytriangle::line_in_triangle(Myline l){
	bool bb=false,b=true;
	float A,B,C,D,a,t,minx,minz,miny,maxx,maxy,maxz;
	Mypoint vv,colxyz;
	vv.x=l.points[1].x-l.points[0].x;
	vv.y=l.points[1].y-l.points[0].y;
	vv.z=l.points[1].z-l.points[0].z;

	A=((points[1].y-points[0].y)*(points[2].z-points[0].z)-(points[2].y-points[0].y)*(points[1].z-points[0].z));
	B=((points[1].z-points[0].z)*(points[2].x-points[0].x)-(points[2].z-points[0].z)*(points[1].x-points[0].x));
	C=((points[1].x-points[0].x)*(points[2].y-points[0].y)-(points[2].x-points[0].x)*(points[1].y-points[0].y));
	D=-points[0].z*(points[1].x-points[0].x)*(points[2].y-points[0].y)-points[0].x*(points[1].y-points[0].y)*(points[2].z-points[0].z)+(points[2].x-points[0].x)*(points[1].y-points[0].y)*points[0].z-points[0].y*(points[1].z-points[0].z)*(points[2].x-points[0].x)+(points[2].y-points[0].y)*(points[1].z-points[0].z)*points[0].x+(points[2].z-points[0].z)*(points[1].x-points[0].x)*points[0].y;
	a=A*vv.x+B*vv.y+C*vv.z;
	if(a!=0){
		t=-(A*l.points[0].x+B*l.points[0].y+C*l.points[0].z+D)/a;
		if(t>=0){
			colxyz.x=points[0].x+vv.x*t;
			colxyz.y=points[0].y+vv.y*t;
			colxyz.z=points[0].z+vv.z*t;
			minx=minf(l.points[0].x,l.points[1].x);
			miny=minf(l.points[0].y,l.points[1].y);
			minz=minf(l.points[0].z,l.points[1].z);
			maxx=maxf(l.points[0].x,l.points[1].x);
			maxy=maxf(l.points[0].y,l.points[1].y);
			maxz=maxf(l.points[0].z,l.points[1].z);

			if(minx<maxx){
				if((colxyz.x>minx)&&(colxyz.x<maxx)){

				}
				else{
					b=false;
				}
			}
			if(miny<maxy){
				if((colxyz.y>miny)&&(colxyz.y<maxy)){

				}
				else{
					b=false;
				}
			}
			if(minz<maxz){
				if((colxyz.z>minz)&&(colxyz.z<maxz)){

				}
				else{
					b=false;
				}
			}
			bb=b;
		}
	}
	if(!bb){
		vv.x=l.points[0].x-l.points[1].x;
		vv.y=l.points[0].y-l.points[1].y;
		vv.z=l.points[0].z-l.points[1].z;

		A=((points[1].y-points[0].y)*(points[2].z-points[0].z)-(points[2].y-points[0].y)*(points[1].z-points[0].z));
		B=((points[1].z-points[0].z)*(points[2].x-points[0].x)-(points[2].z-points[0].z)*(points[1].x-points[0].x));
		C=((points[1].x-points[0].x)*(points[2].y-points[0].y)-(points[2].x-points[0].x)*(points[1].y-points[0].y));
		D=-points[0].z*(points[1].x-points[0].x)*(points[2].y-points[0].y)-points[0].x*(points[1].y-points[0].y)*(points[2].z-points[0].z)+(points[2].x-points[0].x)*(points[1].y-points[0].y)*points[0].z-points[0].y*(points[1].z-points[0].z)*(points[2].x-points[0].x)+(points[2].y-points[0].y)*(points[1].z-points[0].z)*points[0].x+(points[2].z-points[0].z)*(points[1].x-points[0].x)*points[0].y;
		a=A*vv.x+B*vv.y+C*vv.z;
		if(a!=0){
			t=-(A*l.points[1].x+B*l.points[1].y+C*l.points[1].z+D)/a;
			if(t>=0){
				colxyz.x=points[1].x+vv.x*t;
				colxyz.y=points[1].y+vv.y*t;
				colxyz.z=points[1].z+vv.z*t;
				minx=minf(l.points[0].x,l.points[1].x);
				miny=minf(l.points[0].y,l.points[1].y);
				minz=minf(l.points[0].z,l.points[1].z);
				maxx=maxf(l.points[0].x,l.points[1].x);
				maxy=maxf(l.points[0].y,l.points[1].y);
				maxz=maxf(l.points[0].z,l.points[1].z);

				if(minx<maxx){
					if((colxyz.x>minx)&&(colxyz.x<maxx)){

					}
					else{
						b=false;
					}
				}
				if(miny<maxy){
					if((colxyz.y>miny)&&(colxyz.y<maxy)){

					}
					else{
						b=false;
					}
				}
				if(minz<maxz){
					if((colxyz.z>minz)&&(colxyz.z<maxz)){

					}
					else{
						b=false;
					}
				}
				bb=b;
			}
		}
	}
	return bb;
};


bool Mytriangle::tr_in_tr_y(Mytriangle tr){
	bool b=false;
	int i;
	Myline l;
	for(i=0;(!b)&&(i<3);i++){
		if(tr.point_in_triangle_y(this->points[i]))b=true;
	}
	if(!b){
		for(i=0;(!b)&&(i<3);i++){
			l.points[0]=tr.points[i];
			if(i<2){
				l.points[1]=tr.points[i+1];
			}else{
				l.points[1]=tr.points[0];
			}
			if(line_in_triangle_y(l)){
				b=true;
			}
		}
	}
	return b;
};

bool Mytriangle::tr_in_tr_x(Mytriangle tr){
	bool b=false;
	int i;
	Myline l;
	for(i=0;(!b)&&(i<3);i++){
		if(tr.point_in_triangle_x(this->points[i]))b=true;
	}
	if(!b){
		for(i=0;(!b)&&(i<3);i++){
			l.points[0]=tr.points[i];
			if(i<2){
				l.points[1]=tr.points[i+1];
			}else{
				l.points[1]=tr.points[0];
			}
			if(line_in_triangle_x(l)){
				b=true;
			}
		}
	}
	return b;
};


bool Mytriangle::tr_in_tr_z(Mytriangle tr){
	bool b=false;
	int i;
	Myline l;
	for(i=0;(!b)&&(i<3);i++){
		if(tr.point_in_triangle_z(this->points[i]))b=true;
	}
	if(!b){
		for(i=0;(!b)&&(i<3);i++){
			l.points[0]=tr.points[i];
			if(i<2){
				l.points[1]=tr.points[i+1];
			}else{
				l.points[1]=tr.points[0];
			}
			if(line_in_triangle_z(l)){
				b=true;
			}
		}
	}
	return b;
};


//Myobj
void Myobj::show(){
	cout<<"\n V \n";
	v.show();
	cout<<"\n Vn \n";
	cout<<"\n Vt \n";
	cout<<"\n F \n";
	cout<<"\n F.count= "<<f.ff.size()<<"\n";
	f.show();
};

int Myobj::loadfromstr(string str){

	int i,vi,fi,ffi,ii,jj;
	float x,y,z;
	float pp=3.14;				
	float rotmatrx[3][3],rotmatry[3][3],rotmatrz[3][3];
	Mypoint xyz,rotation;
	Mypoint vv;
	Mysquare ff;
	string xx,ss,str1;

	str1=str;
	while(getstrline(str1,xx)){
		i=0;
		ss="";
		while ((xx[i]!=' ')&&(i<xx.length())){
			ss+=xx[i++];                             
		}
		if(ss=="collid"){
			xyz.loadfromstr(xx);
			xyz.show();
		}
		if(ss=="Rotation"){

			rotation.loadfromstr(xx);
			rotation.show();
			for(ii=0;ii<3;ii++)
				for(jj=0;jj<3;jj++){
					rotmatrx[ii][jj]=0;
					rotmatry[ii][jj]=0;
					rotmatrz[ii][jj]=0;
				}
				rotmatrx[1][1]=cos(3.14*rotation.x/pp);
				rotmatrx[1][2]=sin(3.14*rotation.x/pp);
				rotmatrx[2][1]=-sin(3.14*rotation.x/pp);
				rotmatrx[2][2]=cos(3.14*rotation.x/pp);
				rotmatrx[0][0]=1;

				rotmatry[0][0]=cos(3.14*rotation.y/pp);
				rotmatry[0][2]=-sin(3.14*rotation.y/pp);
				rotmatry[2][0]=sin(3.14*rotation.y/pp);
				rotmatry[2][2]=cos(3.14*rotation.y/pp);
				rotmatry[1][1]=1;

				rotmatrz[0][0]=cos(3.14*rotation.z/pp);
				rotmatrz[0][1]=sin(3.14*rotation.z/pp);
				rotmatrz[1][0]=-sin(3.14*rotation.z/pp);
				rotmatrz[1][1]=cos(3.14*rotation.z/pp);
				rotmatrz[2][2]=1;
		}
	}
	vi=0;fi=0;ffi=0;
	str1=str;
	while(getstrline(str1,xx)){
		i=0;
		ss="";
		while((xx[i]!=' ')&&(i<xx.length())){
			ss+=xx[i++];
		}
		if(ss=="v"){
			vv.loadfromstr(xx);
			v.p.push_back(vv);

			vi++;
		}
		if(ss=="f"){
			ff.loadfromstr(xx);
			f.ff.push_back(ff);
		};
	}
	return 0;
};

bool Myobj::in_triangle(int num,Myplayer mp,Myline pl,Mypar par){
	bool bb=false;
	int i;

	Myline l;
	Mysphere sp;
	Mytriangle tr;

	for(i=0;i<3;i++){
		tr.points[i]=this->v.p[this->f.ff[num].fff[i]];
	}
	l.points[0]=mp.point;
	l.points[1]=mp.point;
	l.points[0].y=l.points[0].y-(mp.Height/2);
	l.points[1].y=l.points[1].y+(mp.Height/2);
	if(tr.line_in_triangle_y(l)){
		if(tr.line_in_triangle_x(l)){
			if(tr.line_in_triangle_z(l)){
				if(tr.line_in_triangle(l)){
					bb=true;
					cout<<"tochka\n";
				}	

			}
		}
	}
	if(!bb){
		sp.radius=mp.Radius;
		sp.oxyz=mp.point;
		if(tr.sphere_in_y(sp,pl)){
			bb=true;

		}
		if(bb){
			if(tr_par_z(tr,par)){
				bb=true;
			}else {
				bb=false;
			}
			if(bb){
				if(tr_par_x(tr,par)){
					bb=true;
					cout<<"cylindr\n";
				}else {
					bb=false;
				}
			}
		}

	}

	return bb;
};

//Mygamemap
int Mygamemap::getx(float x){
	int r;
	r=(x-begp.x)/eachcube.x;
	return r;
};
int Mygamemap::getz(float z){
	int r;
	r=(z-begp.z)/eachcube.z;
	return r;
};

int Mygamemap::getnum(int i,int j){
	int r,rz;
	rz=(endp.z-begp.z)/eachcube.z;
	r=i*rz+j;
	return r;
};
void Mygamemap::init(Mypoint p,Mypoint len,Mypoint c){
	float xx,yy,zz;
	Mycube pp;
	Mypoint bufp;

	ps.clear();
	begp=p;
	endp=len;
	eachcube.x=c.x;
	eachcube.y=c.y;
	eachcube.z=c.z;
	xx=p.x;
	while(xx<endp.x){
		pp.p[0].x=xx;
		yy=p.y;
		while(yy<endp.y){
			pp.p[0].y=yy;
			zz=p.z;
			while(zz<endp.z){
				pp.p[0].z=zz;
				ps.push_back(pp);
				zz=zz+c.z;
			}
			yy=yy+c.y;
		}	
		xx=xx+c.x;
	}
	for(int i=0;i<ps.size();i++){
		bufp=ps[i].p[0];

		bufp.x=bufp.x+eachcube.x;
		ps[i].p[1]=bufp;
		bufp.y=bufp.y+eachcube.y;
		ps[i].p[2]=bufp;
		bufp.x=bufp.x-eachcube.x;
		ps[i].p[3]=bufp;
		bufp.z=bufp.z+eachcube.z;
		bufp.y=bufp.y-eachcube.y;
		ps[i].p[4]=bufp;
		bufp.x=bufp.x+eachcube.x;
		ps[i].p[5]=bufp;
		bufp.y=bufp.y+eachcube.y;
		ps[i].p[6]=bufp;
		bufp.x=bufp.x-eachcube.x;
		ps[i].p[7]=bufp;

		ps[i].triang[0].pointnums[0]=0;
		ps[i].triang[0].pointnums[1]=1;
		ps[i].triang[0].pointnums[2]=2;

		ps[i].triang[1].pointnums[0]=2;
		ps[i].triang[1].pointnums[1]=3;
		ps[i].triang[1].pointnums[2]=0;

		ps[i].triang[2].pointnums[0]=1;
		ps[i].triang[2].pointnums[1]=6;
		ps[i].triang[2].pointnums[2]=5;

		ps[i].triang[3].pointnums[0]=6;
		ps[i].triang[3].pointnums[1]=2;
		ps[i].triang[3].pointnums[2]=1;

		ps[i].triang[4].pointnums[0]=5;
		ps[i].triang[4].pointnums[1]=4;
		ps[i].triang[4].pointnums[2]=7;

		ps[i].triang[5].pointnums[0]=5;
		ps[i].triang[5].pointnums[1]=6;
		ps[i].triang[5].pointnums[2]=7;

		ps[i].triang[6].pointnums[0]=4;
		ps[i].triang[6].pointnums[1]=0;
		ps[i].triang[6].pointnums[2]=3;

		ps[i].triang[7].pointnums[0]=4;
		ps[i].triang[7].pointnums[1]=3;
		ps[i].triang[7].pointnums[2]=7;

		//niz
		ps[i].triang[8].pointnums[0]=0;
		ps[i].triang[8].pointnums[1]=1;
		ps[i].triang[8].pointnums[2]=5;

		ps[i].triang[9].pointnums[0]=0;
		ps[i].triang[9].pointnums[1]=5;
		ps[i].triang[9].pointnums[2]=4;

		//vverh
		ps[i].triang[10].pointnums[0]=3;
		ps[i].triang[10].pointnums[1]=2;
		ps[i].triang[10].pointnums[2]=6;

		ps[i].triang[11].pointnums[0]=3;
		ps[i].triang[11].pointnums[1]=6;
		ps[i].triang[11].pointnums[2]=7;
	}
};	


//Myobjs
void Myobjs::find_collobj(int numps, int numobj){
	bool b=false,bb;
	int i,j;
	Mytriangle t1,t2;
	Mymapcollisobj mco;
	for(i=10;i<12;i++){
		for(int ii=0;ii<3;ii++){
			t1.points[ii]=this->mygamemap.ps[numps].p[this->mygamemap.ps[numps].triang[i].pointnums[ii]];

		}
		for(j=0;j<objs[numobj].f.ff.size();j++){
			bb=false;
			for(int ii=0;ii<mygamemap.ps[numps].collisobjs.size();ii++){
				if((numobj==mygamemap.ps[numps].collisobjs[ii].collistr[0])&&(j==mygamemap.ps[numps].collisobjs[ii].collistr[1]))bb=true;
			}
			if(!bb){
				for(int jj=0;jj<3;jj++){
					t2.points[jj]=objs[numobj].v.p[objs[numobj].f.ff[j].fff[jj]];

				}
				if(t2.tr_in_tr_y(t1)){
					b=true;
					mco.collistr[0]=numobj;
					mco.collistr[1]=j;
					this->mygamemap.ps[numps].collisobjs.push_back(mco);	
				}
			}
		}
	}
};

void Myobjs::creategamemap(int num){
	int i,j;
	for(i=0;i<mygamemap.ps.size();i++){
		find_collobj(i,num);
	}

};
