grammar Fun;

topLevel: (def NEWLINE)* def EOF;
def: funcname '::' polytype NEWLINE (decl)+;
funcname: NAME;

// Types
polytype: 'forall' typevar '.' (polytype | monotype);
monotype
    : monotype '->' pureType
    | '(' monotype ')'
    | pureType;
pureType: typevar | primitiveType;
primitiveType: ('integer' | 'boolean' | 'char' | '[' pureType ']');
typevar: NAME;

// Terms
decl: funcname args ('|' condition)? '=' term;
args: (BOT | NAME)*;
term
    : 'let' (decl NEWLINE)* decl 'in'
    | term 'where' (decl NEWLINE)* decl
    | 'if' condition 'then' term 'else' term
    | term term
    | '(' term ')'
    | funcname
    | '[' (primValue ',')* primValue ']'
    | primValue
    ;

condition
    : condition ('&&' | '||' | '~>') condition
    | ('true' | 'false')
    | intTerm ('==' | '/=' | '<' | '>' | '<=' | '>=') intTerm
    ;

intTerm
    : intTerm ('*'|'+'|'-') intTerm
    | INT
    ;

primValue returns [String s]
    : prim = (INT | CHARLIT | STRLIT) { $s = $prim.text; };

// Order is important (omg)
BOT:        '_';
INT:        [+-]?[0-9]+;
NAME:       [a-z][a-zA-Z\'_0-9]*;
CHARLIT:    [\'][a-zA-Z0-9]?[\'];
STRLIT:     [\"][a-zA-Z0-9]*[\"];
NEWLINE:    [\r\n]+;
WS: [ \t\r\n]+ -> skip;