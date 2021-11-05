grammar HydroModels;

// grammar

program : variablesStmt inputStmt outputStmt? modelStmt + END EOF ;

inputStmt : INPUT LEFT_BRACE varDecl+ RIGHT_BRACE ;

varDecl : IDENTIFIER EQUAL expression SEMICOLON ;

variablesStmt : VARIABLES LEFT_BRACE ( varassignments SEMICOLON ) + RIGHT_BRACE ;

modelStmt : MODEL STRING LEFT_BRACE parametersStmt? equationsStmt outputStmt?  RIGHT_BRACE ;

parametersStmt :  PARAMETERS LEFT_BRACE varDecl* RIGHT_BRACE;

varassignments : IDENTIFIER EQUAL expression # idEqualsExpr
                | IDENTIFIER LEFT_PAREN DEFAULT EQUAL expression COMMA LOWER EQUAL expression COMMA UPPER EQUAL expression RIGHT_PAREN #idWithDefault
                | IDENTIFIER LEFT_PAREN expression COMMA expression COMMA expression RIGHT_PAREN #idWithDefault
                | IDENTIFIER LEFT_PAREN LOWER EQUAL expression COMMA UPPER EQUAL expression RIGHT_PAREN #idWithouDefault
                | IDENTIFIER LEFT_PAREN expression COMMA  expression RIGHT_PAREN #idWithouDefault
                ;

equationsStmt : EQUATIONS LEFT_BRACE ( equationassign SEMICOLON)+ RIGHT_BRACE;
equationassign :  expression EQUAL expression #equationAssignEqual
                | expression # equationAssignOneExpression
                ;
outputStmt :  OUTPUT LEFT_BRACE outputDecl+ RIGHT_BRACE;
outputDecl :  STRING COMMA IDENTIFIER SEMICOLON # outputDeclWithoutMul
              | STRING COMMA IDENTIFIER COMMA expression SEMICOLON # outputDeclWithMul
              ;

expression : term  op=( PLUS | MINUS) expression #exprRecursive
            | term #exprTerm
            ;
term : factor op=(STAR | SLASH ) term #termFactorSTARSLASHterm
     | factor  #termFactor
     ;
factor : (op=( PLUS | MINUS) factor)  #unaryFactor
        | power #factorEqualsPower
        ;
power : atom POWER_OP factor  #powerAtomPowerFactor
        | atom #powerAtom
        ;

atom :   IDENTIFIER #atomID
        | NUMBER  #atomNumber
        | COS LEFT_PAREN expression RIGHT_PAREN #atomCos
        | SIN LEFT_PAREN expression RIGHT_PAREN #atomSin
        | EXP LEFT_PAREN expression RIGHT_PAREN #atomExp
        | LN LEFT_PAREN expression RIGHT_PAREN #atomLn
        | LOG10 LEFT_PAREN expression RIGHT_PAREN #atomLog10
        | POWERFUNC LEFT_PAREN expression COMMA expression RIGHT_PAREN #atomPowerFunc
        | LEFT_PAREN expression RIGHT_PAREN #atomParenthesis
        ;

// keywords
MODEL : 'MODEL';
VARIABLES : 'VARIABLES';
PARAMETERS : 'PARAMETERS';
EQUATIONS:'EQUATIONS';
DEFAULT : 'DEFAULT';
LOWER : 'LOWER';
UPPER : 'UPPER';
INPUT : 'INPUT';
OUTPUT : 'OUTPUT';
END : 'END';

// math
LN : 'ln' | 'log';
LOG10 : 'log10';
POWERFUNC : 'pow';
EXP : 'exp';
COS : 'cos';
SIN : 'sin';

LEFT_PAREN : '(' ;
RIGHT_PAREN : ')' ;
LEFT_BRACE : '{' ; 
RIGHT_BRACE : '}' ; 
COMMA : ',';
MINUS : '-';
PLUS : '+';
SEMICOLON : ';';
SLASH : '/';
STAR : '*' ;
EQUAL : '=';
POWER_OP : '^';

IDENTIFIER : (ID_LETTER|'_')('_'|ID_LETTER|DIGIT)*; //FromClanguage 
fragment ID_LETTER :'a'..'z'|'A'..'Z'|'_';
fragment DIGIT :'0'..'9';

STRING : '"' .*? '"';

NUMBER
   : Fractionalconstant Exponentpart?
   ;

fragment Fractionalconstant
   : Digitsequence? '.' Digitsequence
   | Digitsequence '.'
   | Digitsequence 
   ;

fragment Exponentpart
   : 'e' SIGN? Digitsequence
   | 'E' SIGN? Digitsequence
   ;

fragment SIGN
   : [+-]
   ;

fragment Digitsequence
   : DIGIT ('\''? DIGIT)*
   ;

COMMENTS : '#' .*? '\r'? '\n' -> skip;
BLOCKCOMMENT
   : '/*' .*? '*/' -> skip
   ;
WS  : [ \t\r\n]+ -> skip ;
