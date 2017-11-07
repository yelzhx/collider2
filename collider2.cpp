#include "myobj.h"
....

EXPORT bool  check_pos(float x,float y,float z,float h){ // x,y,z координаты,  h- высота игрока 
	bool bb=false;
	int i,ci,cj,ki,kj,ii,colsize;
	Myline pl;
	
	//---------------------------------
	//инициализация текущего состояния игрока
	if(h==0){
		player.Height=pheight-0.01;
	}
	else{
		player.Height=h-0.01;
	}
	player.Height=pheight-0.01;
	player.point.x=x;
	player.point.y=y;
	player.point.z=z;

		pl.points[0].x=player.point.x;
		pl.points[0].z=player.point.z;
		pl.points[0].y=player.point.y-(r2-0.0);
		pl.points[1].x=player.point.x;
		pl.points[1].z=player.point.z;
		pl.points[1].y=player.point.y+(r2-0.0);

		par.points[0].x=player.point.x-(r2);
		par.points[0].z=player.point.z-(r2);
//		par.points[0].y=player.point.y-(h2-r2);
		par.points[0].y=player.point.y-(r2-0.0);

		par.points[1].x=player.point.x-(r2);
		par.points[1].z=player.point.z-(r2);
//		par.points[1].y=player.point.y+(h2-r2);
		par.points[1].y=player.point.y+(r2-0.0);

		par.points[2].x=player.point.x+(r2);
		par.points[2].z=player.point.z+(r2);
//		par.points[2].y=player.point.y+(h2-r2);
		par.points[2].y=player.point.y+(r2-0.0);

		par.points[3].x=player.point.x+(r2);
		par.points[3].z=player.point.z+(r2);
//		par.points[3].y=player.point.y-(h2-r2);
		par.points[3].y=player.point.y-(r2-0.0);

	//определение номеров клеток по координатам
	ci=myobjs.mygamemap.getx(x);
	cj=myobjs.mygamemap.getz(z);
	//обход найденной клетки и соседних клеток
	//ii=myobjs.mygamemap.getnum(ci,cj);
	//cout<<ii<<"\n";		
	for(ki=ci-1;(!bb)&&(ki<=ci+1);ki++){
		for(kj=cj-1;(!bb)&&(kj<=cj+1);kj++){
			//определение номера клетки в одномерном массиве
			ii=myobjs.mygamemap.getnum(ki,kj);
			if(ii<myobjs.mygamemap.ps.size()){
				if(myobjs.mygamemap.ps[ii].collisobjs.size()>0){
					if(myobjs.mygamemap.ps[ii].pl_in_cube(player)){			//если игрок в хотя бы частично в текущей клетке, то начинаем проверку
						i=0;
						colsize=myobjs.mygamemap.ps[ii].collisobjs.size();
						while((i<colsize)&&(!bb)){			
							if(myobjs.objs[myobjs.mygamemap.ps[ii].collisobjs[i].collistr[0]].in_triangle(myobjs.mygamemap.ps[ii].collisobjs[i].collistr[1],player,pl,par)){
								bb=true;
							}
							i++;
						}
					}
				}
			}
		}
	}
	

	return bb;
}


....
	
	
	
EXPORT bool  check_pos_all(float x,float y,float z,float h){
	bool bb=false;
	int i,j,k;
	Myline pl;
	Mytriangle tr;
	
	//---------------------------------
	//инициализация текущего состояния игрока
	if(h==0){
		player.Height=pheight;
	}
	else{
		player.Height=h;
	}
player.Height=pheight;
	player.point.x=x;
	player.point.y=y;
	player.point.z=z;

		pl.points[0].x=player.point.x;
		pl.points[0].z=player.point.z;
		pl.points[0].y=player.point.y-(r2-0.1);
		pl.points[1].x=player.point.x;
		pl.points[1].z=player.point.z;
		pl.points[1].y=player.point.y+(r2-0.1);

		par.points[0].x=player.point.x-(r2);
		par.points[0].z=player.point.z-(r2);
//		par.points[0].y=player.point.y-(h2-r2);
		par.points[0].y=player.point.y-(r2);

		par.points[1].x=player.point.x-(r2);
		par.points[1].z=player.point.z-(r2);
//		par.points[1].y=player.point.y+(h2-r2);
		par.points[1].y=player.point.y+(r2);

		par.points[2].x=player.point.x+(r2);
		par.points[2].z=player.point.z+(r2);
//		par.points[2].y=player.point.y+(h2-r2);
		par.points[2].y=player.point.y+(r2);

		par.points[3].x=player.point.x+(r2);
		par.points[3].z=player.point.z+(r2);
//		par.points[3].y=player.point.y-(h2-r2);
		par.points[3].y=player.point.y-(r2);
	for(i=0;(!bb)&&(i<myobjs.objs.size());i++){
		for(j=0;(!bb)&&(j<myobjs.objs[i].f.ff.size());j++){
		/*	for(k=0;k<3;k++){
				tr.points[k]=myobjs.objs[i].v.p[myobjs.objs[i].f.ff[j].fff[k]];
			}*/
			if(myobjs.objs[i].in_triangle(j,player,pl,par)){
				bb=true;
				break;
			}
		}
	}

	return bb;
}
