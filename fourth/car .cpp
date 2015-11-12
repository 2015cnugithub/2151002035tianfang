#include<stdio.h>
#include<graphics.h>
#include<conio.h>
//����ͼ��
class Figure														
{
public :
	Figure(){}
	virtual void draw()=0;
	virtual void move(double xx ,double yy)= 0;
	virtual void erase()=0;
	virtual double isOut(){return 0;}
	~Figure(){}
protected :
	double x  ;
	double y ;
		
};



class Circle : public Figure
{
public:
	Circle(){}
	//Circle(double cx,double cy);
	Circle(double cx,double cy,double cradius);
	virtual void draw();
	virtual void erase();
	virtual void move(double xx ,double yy);
	virtual double isOut(){if(x-radius>800) return 1; return 0;}
	~Circle(){}
protected:
	// const double radius = 5; 
	double radius;


};

class Rectangle1 : public Figure
{
public:
	Rectangle1(){}
	Rectangle1(double rLeft,double rRight,double rTop,double rBottom);
	virtual void draw();
	virtual void erase();
	virtual void move(double xx ,double yy);
	virtual double isOut(){if(left>800) return 1; return 0;}
	~Rectangle1(){}
protected:
	double left;
	double right;
	double top;
	double bottom;
};

class Triangle : public Figure
{
public:
	Triangle(){}
	Triangle(double tTop1,double tTop2,double tBottom1,double tBottom2);
	virtual void draw();
	virtual void erase();
	virtual void move(double xx ,double yy);
	~Triangle(){}
protected:
	double top1;
	double top2;
	double bottom1;
	double bottom2;

};
/*Circle::Circle(double cx,double cy)
{
	x=cx;
	y=cy;
}*/
Circle::Circle(double cx,double cy,double cradius)
{
	x=cx;
	y=cy;
	radius = cradius;
}
void Circle :: draw(){
/*	setfillcolor(WHITE);
	fillcircle(x,y,radius);
	*/
	setlinecolor(WHITE);
	circle(x,y,radius);
}
void Circle:: move(double xx ,double yy){
 
		x +=xx;
		y +=yy;
}
void Circle ::erase(){
/*	setfillcolor(BLACK);
	fillcircle(x,y,radius);
*/
	setlinecolor(BLACK);
	circle(x,y,radius);
}

Rectangle1:: Rectangle1(double rLeft,double rRight,double rTop,double rBottom)
{
	left = rLeft;
	right = rRight;
	top = rTop;
	bottom = rBottom;
}

void Rectangle1 :: draw(){
	/*setfillcolor(WHITE);
	fillrectangle(left,top,right,bottom);*/
	setlinecolor(WHITE);
	rectangle(left,top,right,bottom);
}
void Rectangle1 ::erase(){
	/*setfillcolor(BLACK);
	fillrectangle(left,top,right,bottom);*/
	setlinecolor(BLACK);
	rectangle(left,top,right,bottom);
}
void Rectangle1:: move(double xx ,double yy ){
 
	left +=xx;
	right +=xx;
	top +=yy;
	bottom +=yy;
}

Triangle::Triangle(double tTop1,double tTop2,double tBottom1,double tBottom2){
top1 = tTop1;			//top1Ϊ�󶥵�x��
top2 = tTop2;			//top2Ϊ�Ҷ���x��
bottom1 = tBottom1;		//bottom1Ϊ�󶥵�y��
bottom2 = tBottom2;		//bottom2Ϊ�Ҷ���y��
}
void Triangle ::draw(){
	//setfillcolor(WHITE);
	setlinecolor(WHITE);
	line(top1,bottom1,top2,bottom2);
	line(top1,bottom1,top2,bottom1);
	line(top2,bottom1,top2,bottom2);
}
void Triangle :: erase(){
	//setfillcolor(BLACK);
	setlinecolor(BLACK);
	line(top1,bottom1,top2,bottom2);
	line(top1,bottom1,top2,bottom1);
	line(top2,bottom1,top2,bottom2);
}
void Triangle :: move(double xx,double yy){
	top1 +=xx;
	top2 +=xx;
	bottom1 +=yy;
	bottom2 +=yy;
}

//ָ����
class FigureLink
{
	Figure *data;
	FigureLink *next;
public:
	FigureLink (){data = 0;next = 0;}
	~FigureLink(){
		//Figure *p,*q;
	}
	void set(Figure *k)
	{
		data = k;
	}
	void setNext(FigureLink *k)
	{
		next = k ;
	}
	Figure *get()
	{
		return data;
	}
	FigureLink *getNext()
	{
		return next;
	}

};

//������������������
class Vehicle
{
public:
	Vehicle(){}
	virtual void draw() = 0;
	virtual void hide() = 0;
	virtual void move(double x,double y) = 0;
	virtual double isOut() = 0;
protected:
	FigureLink contents;
	FigureLink *head;
};
class Car :public Vehicle
{
public:
	Car(){}
	Car(Figure *a[20],double k);
	virtual void draw ();
	virtual void hide();
	virtual void move(double x ,double y);
	virtual double isOut();
	~Car(){}
};
class Truck : public Vehicle
{
public:
	Truck(){}
	Truck(Figure *a[20],double k);
	virtual void draw();
	virtual void hide();
	virtual void move(double x ,double y);
	virtual double isOut();
	~Truck(){}
};
Car :: Car(Figure *a[20],double k)									
{
	head =&contents;			
	FigureLink *p = head;
	for(int i = 0; i<k;i++)
	{
		head = new FigureLink;
		head->set(a[i]);
		//p=head;
		p->setNext(head);
		p=head;
	}

}

void Car :: draw()
{
	FigureLink *p = contents.getNext();
	Figure *cast;
	while (/*p->getNext()!=NULL*/1)
	{
		cast = p->get();
		cast->draw();
		p=p->getNext();
		if(p==NULL)
			return ;
	}

}

void Car::hide()
{
	FigureLink *p =contents.getNext();
	Figure * cast;
	while(/*p->getNext()!=null*/1)
	{
		cast = p->get();
		cast->erase();
		p=p->getNext();
		if(p==NULL)
			return;
	}
}
void Car::move(double x ,double y)
{
	FigureLink *p = contents.getNext();
	Figure *cast;
	while(/*p->getNext()!=null*/1)
	{
		cast = p->get();
		cast->move(x ,y);
		p=p->getNext();
		if(p==NULL) return;
	}
}
double Car ::isOut()
{
	FigureLink *p=contents.getNext();
	Figure *cast;
	cast=p->get();
	if(cast->isOut()==1) return 1;
	return 0;
}
Truck::Truck(Figure *a[20],double k)
{
	head =&contents;
	FigureLink *p = head;
	for(int i = 0; i<k;i++)
	{
		head = new FigureLink;
		head->set(a[i]);
		p->setNext(head);
		p=head;
	}

}

void Truck :: draw()
{
	FigureLink *p = contents.getNext();
	Figure *cast;
	while (/*p->getNext()!=null*/1)
	{
		cast = p->get();
		cast->draw();
		p=p->getNext();
		if(p==NULL)
			return ;
	}

}

void Truck::hide()
{
	FigureLink *p =contents.getNext();
	Figure * cast;
	while(/*p->getNext()!=null*/1)
	{
		cast = p->get();
		cast->erase();
		p=p->getNext();
		if(p==NULL)
			return;
	}
}
void Truck::move(double x ,double y)
{
	FigureLink *p = contents.getNext();
	Figure *cast;
	while(/*p->getNext()!=null*/1)
	{
		cast = p->get();
		cast->move(x,y);
		p=p->getNext();
		if(p==NULL) return;
	}
}
double Truck ::isOut()
{
	FigureLink *p=contents.getNext();
	Figure *cast;
	cast=p->get();
	if(cast->isOut()==1) return 1;
	return 0;
}

void animate(Vehicle *p, double velo)
{
//	for(double i=0;i<10;i++)
	while(!p->isOut())

	{
		p->hide();
		p->move(velo,0);
		p->draw();

		Sleep(50);
		 if(kbhit())							//kbhit() ��ִ��ʱ,����Ƿ��а�������,�а��·��ط�0ֵ��һ����1;û�а��·���0;�Ƿ���������;getch() ��ִ��ʱ,��ⰴ��ʲô��,����������ú���������;����������

		 {
			 char c=getch();
			 switch(c)
			 {
			 case ' ': velo+=10; break;
			 case 'a': if(velo>=10) velo-=10; break;
			 default:;break;
			 }
		//	 else if(getch()
		 }
	}

}
double main()
{
	initgraph(640,480);
	const double d= 10.0;
	const double gy=300.0;

	Circle c1(1.75*d,2.5*d+300,5),c2(6.25*d,2.5*d+300,5),c3(d,4.5*d+300,5),c4(2.25*d,4.5*d+300,5),c5(6.75*d,4.5*d+300,5),c6(8*d,4.5*d+300,5),c7(10*d+2,4.5*d+300,5);
	Rectangle1 r1(2.25*d,5.75*d,300,300+d),r2(0,8*d,300+d,300+2*d),r3(0,9*d,300,300+4*d),r4(9*d+2,11*d+2,300+d,300+4*d);
	

	Triangle t1(1.25*d,2.25*d,300+d,300),t2(6.75*d,5.75*d,300+d,300);
	
	Figure *fc[10];
	fc[0] = &c1;
	fc[1] = &r1;
	fc[2] = &t2;
	fc[3] = &r2;
	fc[4] = &c2;
	fc[5] = &t1;
	Figure *ft[10];
	ft[0] = &r3;
	ft[1] = &c3;
	ft[2] = &c4;
	ft[3] = &c5;
	ft[4] = &c6;
	ft[5] = &r4;
	ft[6] = &c7;
	Car c(fc,6);
	Truck t(ft,7);
	Vehicle *vc = &c,*vt =&t;
	vc->draw();
	animate(vc,10);
//	vt->draw();
//	animate(vt,10);
	
	
	getch();
	closegraph();
	return 0;

}





