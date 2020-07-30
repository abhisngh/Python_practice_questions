#include<iostream>
using namespace std;

#define INF 100000 
class point{

	public:
		int x;
		int y;
};


//Check if the point q lies in the line pr
bool check(point p,point q,point r){
	if(q.x<=max(p.x,r.x) && q.x>=min(p.x,q.x) && q.y<=max(p.y,r.y) && q.y>=min(p.y,r.y))
	{
		return true;
	}
	return false;
}

int orientation(point p,point q,point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	//Colinear
	if(val==0)
	{
		return 0;
	}
	//Clock-wise or anti clockwise
	return (val>0)?1:2;
}

bool checkInteresect(point p1,point q1,point p2,point q2)
{
	int ot1=orientation(p1,q1,p2);
	int ot2=orientation(p1,q1,q2);
	int ot3=orientation(p2,q2,p1);
	int ot4=orientation(p2,q2,q1);

	if(ot1!=ot2 && ot3!=ot4)
	{
		return true;
	}

	if(ot1 == 0 && check(p1, p2, q1))
	{
		return true;
	}

	if (ot2 == 0 && check(p1, q2, q1)) 
	{
		return true;
	}
	if (ot3 == 0 && check(p2, p1, q2))
	{ 
		return true;
	}
	if(ot4==0 && check(p2, q1, q2))
	{
		return true;
	}

	return false;
}

bool checkInside(point polygon[],int n, point p)
{

	if(n<3)
	{
		return false;
	}
	point extreme = {INF, p.y};

	    int count = 0, i = 0; 
    do
    { 
        int next = (i+1)%n; 
  
        if (checkInteresect(polygon[i], polygon[next], p, extreme)) 
        { 

            if (orientation(polygon[i], p, polygon[next]) == 0) 
               return check(polygon[i], p, polygon[next]); 
  
            count++; 
        } 
        i = next; 
    } while (i != 0); 
  
    return count&1;  
} 

int main()
{
	point polygon[] = {{1, 0}, {8, 3}, {8, 8}, {1,5}}; 
    int n = sizeof(polygon)/sizeof(polygon[0]); 
    point p = {3, 5};
    if(checkInside(polygon,n,p))
    {
    	cout<<"True";
    }
    else
    {
    	cout<<"No";
    }

	return 0;
}