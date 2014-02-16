/*
 *   RapCAD - Rapid prototyping CAD IDE (www.rapcad.org)
 *   Copyright (C) 2010-2014 Giles Bathgate
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "simpletextbuilder.h"
#include "polyhedron.h"

QMap<QChar,Char>* SimpleTextBuilder::characters=NULL;

SimpleTextBuilder::SimpleTextBuilder()
{
	if(!characters) {
		characters=new QMap<QChar,Char>();
		Polygon* stroke;

		QList<Polygon*> zero;
		stroke=new Polygon();
		stroke->append(Point(0.25,1.6,0.0));
		stroke->append(Point(0.75,1.6,0.0));
		stroke->append(Point(1.0 ,1.4,0.0));
		stroke->append(Point(1.0 ,0.2,0.0));
		stroke->append(Point(0.75,0.0,0.0));
		stroke->append(Point(0.25,0.0,0.0));
		stroke->append(Point(0.0 ,0.2,0.0));
		stroke->append(Point(0.0 ,1.4,0.0));
		stroke->append(Point(0.25,1.6,0.0));
		zero.append(stroke);
		stroke=new Polygon();
		stroke->append(Point(1.0,1.4,0.0));
		stroke->append(Point(0.0,0.2,0.0));
		zero.append(stroke);
		characters->insert('0',zero);

		QList<Polygon*> one;
		stroke=new Polygon();
		stroke->append(Point(0.25,1.2,0.0));
		stroke->append(Point(0.5 ,1.6,0.0));
		stroke->append(Point(0.5 ,0.0,0.0));
		one.append(stroke);
		characters->insert('1',one);

		QList<Polygon*> two;
		stroke=new Polygon();
		stroke->append(Point(0.0 ,1.4,0.0));
		stroke->append(Point(0.25,1.6,0.0));
		stroke->append(Point(0.75,1.6,0.0));
		stroke->append(Point(1.0, 1.4,0.0));
		stroke->append(Point(1.0, 1.0,0.0));
		stroke->append(Point(0.0, 0.0,0.0));
		stroke->append(Point(1.0, 0.0,0.0));
		two.append(stroke);
		characters->insert('2',two);

		QList<Polygon*> three;
		stroke=new Polygon();
		stroke->append(Point(0.0, 1.4,0.0));
		stroke->append(Point(0.25,1.6,0.0));
		stroke->append(Point(0.75,1.6,0.0));
		stroke->append(Point(1.0, 1.4,0.0));
		stroke->append(Point(1.0, 1.0,0.0));
		stroke->append(Point(0.75,0.8,0.0));
		stroke->append(Point(1.0, 0.6,0.0));
		stroke->append(Point(1.0, 0.2,0.0));
		stroke->append(Point(0.75,0.0,0.0));
		stroke->append(Point(0.25,0.0,0.0));
		stroke->append(Point(0.0, 0.2,0.0));
		three.append(stroke);
		stroke=new Polygon();
		stroke->append(Point(0.25,0.8,0.0));
		stroke->append(Point(0.75,0.8,0.0));
		three.append(stroke);
		characters->insert('3',three);

		QList<Polygon*> four;
		stroke=new Polygon();
		stroke->append(Point(0.75,0.0,0.0));
		stroke->append(Point(0.75,1.6,0.0));
		stroke->append(Point(0.0,0.6,0.0));
		stroke->append(Point(1.0,0.6,0.0));
		four.append(stroke);
		characters->insert('4',four);

		QList<Polygon*> five;
		stroke=new Polygon();
		stroke->append(Point(1.0, 1.6,0.0));
		stroke->append(Point(0.0, 1.6,0.0));
		stroke->append(Point(0.0, 0.8,0.0));
		stroke->append(Point(0.75,0.8,0.0));
		stroke->append(Point(1.0, 0.6,0.0));
		stroke->append(Point(1.0, 0.2,0.0));
		stroke->append(Point(0.75,0.0,0.0));
		stroke->append(Point(0.25,0.0,0.0));
		stroke->append(Point(0.0 ,0.2,0.0));
		five.append(stroke);
		characters->insert('5',five);

		QList<Polygon*> six;
		stroke=new Polygon();
		stroke->append(Point(1.0, 1.4,0.0));
		stroke->append(Point(0.75,1.6,0.0));
		stroke->append(Point(0.25,1.6,0.0));
		stroke->append(Point(0.0, 1.4,0.0));
		stroke->append(Point(0.0, 0.2,0.0));
		stroke->append(Point(0.25,0.0,0.0));
		stroke->append(Point(0.75,0.0,0.0));
		stroke->append(Point(1.0, 0.2,0.0));
		stroke->append(Point(1.0, 0.6,0.0));
		stroke->append(Point(0.75,0.8,0.0));
		stroke->append(Point(0.0, 0.8,0.0));
		six.append(stroke);
		characters->insert('6',six);

		QList<Polygon*> seven;
		stroke=new Polygon();
		stroke->append(Point(0.0, 1.6,0.0));
		stroke->append(Point(0.75,1.6,0.0));
		stroke->append(Point(1.0, 1.4,0.0));
		stroke->append(Point(0.0, 0.0,0.0));
		seven.append(stroke);
		characters->insert('7',seven);

		QList<Polygon*> eight;
		stroke=new Polygon();
		stroke->append(Point(0.25,0.8,0.0));
		stroke->append(Point(0.0, 1.0,0.0));
		stroke->append(Point(0.0, 1.4,0.0));
		stroke->append(Point(0.25,1.6,0.0));
		stroke->append(Point(0.75,1.6,0.0));
		stroke->append(Point(1.0, 1.4,0.0));
		stroke->append(Point(1.0, 1.0,0.0));
		stroke->append(Point(0.75,0.8,0.0));
		stroke->append(Point(0.25,0.8,0.0));
		stroke->append(Point(0.0, 0.6,0.0));
		stroke->append(Point(0.0, 0.2,0.0));
		stroke->append(Point(0.25,0.0,0.0));
		stroke->append(Point(0.75,0.0,0.0));
		stroke->append(Point(1.0, 0.2,0.0));
		stroke->append(Point(1.0, 0.6,0.0));
		stroke->append(Point(0.75,0.8,0.0));
		eight.append(stroke);
		characters->insert('8',eight);

		QList<Polygon*> nine;
		stroke=new Polygon();
		stroke->append(Point(1.0, 1.0,0.0));
		stroke->append(Point(0.75,0.8,0.0));
		stroke->append(Point(0.25,0.8,0.0));
		stroke->append(Point(0.0, 1.0,0.0));
		stroke->append(Point(0.0, 1.4,0.0));
		stroke->append(Point(0.25,1.6,0.0));
		stroke->append(Point(0.75,1.6,0.0));
		stroke->append(Point(1.0, 1.4,0.0));
		stroke->append(Point(1.0, 0.0,0.0));
		nine.append(stroke);
		characters->insert('9',nine);

		QList<Polygon*> point;
		stroke=new Polygon();
		stroke->append(Point(0.0, 0.0,0.0));
		stroke->append(Point(0.0, 0.2,0.0));
		stroke->append(Point(0.25,0.2,0.0));
		stroke->append(Point(0.25,0.0,0.0));
		stroke->append(Point(0.0, 0.0,0.0));
		point.append(stroke);
		characters->insert('.',point);

		QList<Polygon*> minus;
		stroke=new Polygon();
		stroke->append(Point(0.0,0.8,0.0));
		stroke->append(Point(1.0,0.8,0.0));
		minus.append(stroke);
		characters->insert('-',minus);
	}
}

void SimpleTextBuilder::setText(QString t)
{
	text=t;
}

decimal SimpleTextBuilder::getHeight()
{
	return 1.6;
}

void SimpleTextBuilder::setLocation(Point p)
{
	location=p;
}

Primitive* SimpleTextBuilder::buildPrimitive() const
{
	Polyhedron* result=new Polyhedron();
	result->setType(Primitive::Skeleton);

	decimal x,y,z;
	location.getXYZ(x,y,z);
	foreach(QChar c, text){
		Char ch=characters->value(c);
		foreach(Polygon* p, ch) {
			result->createPolygon();
			foreach (Point pt, p->getPoints()) {
				decimal cx,cy,cz;
				pt.getXYZ(cx,cy,cz);
				result->appendVertex(Point(cx+x,cy+y,cz+z));
			}
		}
		if(c=='.')
			x+=0.75;
		else
			x+=1.5;
	}

	return result;
}
