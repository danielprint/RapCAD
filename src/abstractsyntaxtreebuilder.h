/*
 *   RapCAD - Rapid prototyping CAD IDE (www.rapcad.org)
 *   Copyright (C) 2010  Giles Bathgate
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

#ifndef ABSTRACTSYNTAXTREEBUILDER_H
#define ABSTRACTSYNTAXTREEBUILDER_H

#include <QVector>
#include "module.h"
#include "parameter.h"
#include "literal.h"
#include "value.h"
#include "expression.h"
#include "binaryexpression.h"
#include "declaration.h"
#include "context.h"
#include "modulecontext.h"
#include "functioncontext.h"
#include "instance.h"
#include "argument.h"
#include "function.h"
#include "statement.h"
#include "compoundstatement.h"
#include "assignstatement.h"
#include "vectorexpression.h"

class AbstractSyntaxTreeBuilder
{
public:
    virtual ~AbstractSyntaxTreeBuilder(){}
    virtual void BuildScript(QVector<Declaration*>*)=0;
    virtual QVector<Declaration*>* BuildDeclarations()=0;
    virtual QVector<Declaration*>* BuildDeclarations(Declaration*)=0;
    virtual QVector<Declaration*>* BuildDeclarations(QVector<Declaration*>*)=0;
    virtual QVector<Declaration*>* BuildDeclarations(QVector<Declaration*>*,Declaration*)=0;
    virtual Statement* BuildStatement(Statement*)=0;
    virtual Statement* BuildStatement(QVector<Statement*>*)=0;
    virtual Statement* BuildStatement(Value*,Expression*)=0;
    virtual Statement* BuildStatement(QString*,Value::Type_e,Expression*)=0;
    virtual QVector<Statement*>* BuildStatements()=0;
    virtual QVector<Statement*>* BuildStatements(Statement*)=0;
    virtual QVector<Statement*>* BuildStatements(QVector<Statement*>*)=0;
    virtual QVector<Statement*>* BuildStatements(QVector<Statement*>*,Statement*)=0;
    virtual Declaration* BuildModule(QString*,QVector<Parameter*>*,Context*)=0;
    virtual Declaration* BuildFunction(QString*,QVector<Parameter*>*,Context*)=0;
    virtual Context* BuildContext(QVector<Declaration*>*)=0;
    virtual Context* BuildContext(Instance*)=0;
    virtual Context* BuildContext(Expression*)=0;
    virtual Context* BuildContext(QVector<Statement*>*)=0;
    virtual Instance* BuildInstance(Instance*)=0;
    virtual Instance* BuildInstance(QString*,QVector<Argument*>*)=0;
    virtual Instance* BuildInstance(Instance*,QVector<Instance*>*)=0;
    virtual QVector<Instance*>* BuildInstances()=0;
    virtual QVector<Instance*>* BuildInstances(Instance*)=0;
    virtual QVector<Instance*>* BuildInstances(QVector<Instance*>*)=0;
    virtual QVector<Instance*>* BuildInstances(QVector<Instance*>*,Instance*)=0;
    virtual QVector<Parameter*>* BuildParameters()=0;
    virtual QVector<Parameter*>* BuildParameters(Parameter*)=0;
    virtual QVector<Parameter*>* BuildParameters(QVector<Parameter*>*,Parameter*)=0;
    virtual Parameter* BuildParameter(QString*)=0;
    virtual Parameter* BuildParameter(QString*,Expression*)=0;
    virtual QVector<Argument*>* BuildArguments()=0;
    virtual QVector<Argument*>* BuildArguments(Argument*)=0;
    virtual QVector<Argument*>* BuildArguments(QVector<Argument*>*,unsigned int,Argument*)=0;
    virtual unsigned int BuildOptionalCommas()=0;
    virtual unsigned int BuildOptionalCommas(unsigned int)=0;
    virtual Argument* BuildArgument(Expression*)=0;
    virtual Argument* BuildArgument(Value*,Expression*)=0;
    virtual Expression* BuildLiteral()=0;
    virtual Expression* BuildLiteral(bool)=0;
    virtual Expression* BuildLiteral(double value)=0;
    virtual Expression* BuildLiteral(QString* value)=0;
    virtual Value* BuildVariable(QString* name)=0;
    virtual Expression* BuildVariable(Value*)=0;
    virtual Value* BuildVariable(QString*,Value::Type_e)=0;
    virtual Expression* BuildExpression(Expression*,Expression::Operator_e,Expression*)=0;
    virtual Expression* BuildExpression(QVector<Expression*>*)=0;
    virtual QVector<Expression*>* BuildVector()=0;
    virtual QVector<Expression*>* BuildVector(Expression*)=0;
    virtual QVector<Expression*>* BuildVector(QVector<Expression*>*,Expression*)=0;
};

#endif // ABSTRACTSYNTAXTREEBUILDER_H
