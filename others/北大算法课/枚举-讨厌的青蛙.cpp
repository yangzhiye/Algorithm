#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int r,c,n;
struct PLANT{
	int x,y;
};
PLANT plants[5001];
PLANT plant;

bool operator <(const PLANT &p1,const PLANT &p2){
	if(p1.x==p2.x)
		return p1.y<p2.y;
	return p1.x<p2.x;
}

int searchPath(PLANT secPlant,int dX,int dY){
	PLANT plant;
	int steps;
	plant.x = secPlant.x+dX;
	plant.y = secPlant.y+dY;
	steps = 2;
	while(plant.x<=r&&plant.x>=1&&plant.y<=c&&plant.y>=1){
		if(!binary_search(plants, plants+n, plant)){
			steps = 0;
			break;
		}
		plant.x+=dX;
		plant.y+=dY;
		steps++;
	}
	return steps;
}
int main(int argc, char *argv[]) {
	int i,j,dX,dY,pX,pY,steps,max=2;
	cin>>r>>c>>n;
	for(i = 0 ; i < n ; ++i)
		cin>>plants[i].x>>plants[i].y;
	sort(plants, plants+n);
	for(i = 0 ; i < n ; ++i)
		for(j = i + 1 ; j<n ; ++j)
		{
			dX = plants[j].x-plants[i].x;
			dY = plants[j].y-plants[i].y;
			pX = plants[i].x - dX;
			pY = plants[i].y - dY;
			if(pX<=r&&pX>=1&&pY<=c&&pY>=1)
				continue;
			if(plants[i].x+(max-1)*dX>r)
				break;
			pY = plants[i].y+(max-1)*dY;
			if(pY>c||pY<1)
				continue;
			steps = searchPath(plants[j],dX,dY);
			if(steps>max)
				max = steps;
		}
		if(2==max)
			max = 0;
		cout<<max<<endl;
}