
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     EQV = 258,
     IMP = 259,
     XOR = 260,
     OR = 261,
     AND = 262,
     NOT = 263,
     OP_EQ = 264,
     OP_REL = 265,
     OP_ASSIGN = 266,
     OP_ADD_SUB = 267,
     OP_MUL_DIV = 268,
     REAL = 269,
     INT = 270,
     BOOL = 271,
     COUNT = 272,
     UNDEF = 273,
     CONSTFUNC = 274,
     WITHOUT_PARAM_FUNC_TIME = 275,
     STVAR_NAME = 276,
     WITHOUT_PARAM_FUNC_RANDOM = 277,
     PORTREF = 278,
     SEND = 279,
     CELLPOS = 280,
     BINARY_FUNC = 281,
     BINARY_FUNC_RANDOM = 282,
     COND3_FUNC = 283,
     COND4_FUNC = 284,
     STATECOUNT = 285,
     UNARY_FUNC = 286,
     COND_REAL_FUNC = 287,
     UNARY_FUNC_RANDOM = 288,
     PORTNAME = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 43 "gram.y"

	struct {
		SyntaxNode *Node ;
		int Stochastic;
	} PSyntaxNode;

  	struct {
		ANDNode *Node;
		int Stochastic;
	} PBinaryNode;

	struct {
		NOTNode *Node;
		int Stochastic;
	} PUnaryNode ;

  	struct {
		IFNode *Node;
		int Stochastic;
	} P3Node ;

  	struct {
		IFUNode *Node;
		int Stochastic;
	} P4Node ;

	struct {
		AssignNode *Node;
		int Stochastic;
	} PAssignNode;
	
	struct {
		ListNode *Node;
		int Stochastic;
	} PListNode;

	struct {
		nTupla	*Node;
	} PTupla ;
	
    struct {
       v_tuple *Node;
    } PTupleBody;



/* Line 1676 of yacc.c  */
#line 133 "gram.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


