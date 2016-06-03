grammar Grammar;

@parser::header {
package ru.ctddev.filippov.pg;
}

main : (NEWLINE* header NEWLINE*) (NEWLINE* members NEWLINE*) (((curRule ';' NEWLINE) | NEWLINE)*);

header : '@header' JAVACODE NEWLINE #HeaderLabel;

members : '@members' JAVACODE  NEWLINE #MembersLabel;

curRule : NON_TERM_NAME declRet ? ':' nonTermProduction ('|' nonTermProduction)* # NonTermLabel
        | TERM_NAME ':' termProduction ('|' termProduction)* # TermLabel;

nonTermProduction : (nodeNonTermProduction)* JAVACODE?;
nodeNonTermProduction : NON_TERM_NAME | TERM_NAME;
termProduction : ('\'' (NON_TERM_NAME | LEFT_PAREN | RIGHT_PAREN) '\'')*;

declRet : 'returns' '[' type ']';
type : NON_TERM_NAME | TERM_NAME | MIX_CASE_NAME;

NEWLINE:'\r'? '\n' ;
NON_TERM_NAME : [_a-z]+;
TERM_NAME : [_A-Z]+;
MIX_CASE_NAME : [_a-zA-Z]+;
JAVACODE : '{' (~('}'|'{')+ JAVACODE?)* '}';
LEFT_PAREN : '(';
RIGHT_PAREN : ')';
WS : [ \t]+ -> skip ;
