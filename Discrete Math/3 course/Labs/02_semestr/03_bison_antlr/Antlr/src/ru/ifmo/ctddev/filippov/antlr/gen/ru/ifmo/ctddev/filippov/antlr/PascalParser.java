// Generated from /home/dmitry/Documents/work/git/ITMO/Discrete Math/3 course/Labs/02_semestr/03_bison_antlr/Antlr/src/ru/ifmo/ctddev/filippov/antlr/Pascal.g4 by ANTLR 4.5.1
package ru.ifmo.ctddev.filippov.antlr.gen.ru.ifmo.ctddev.filippov.antlr;

import java.util.HashSet;
import java.util.HashMap;
import java.util.Collections;
import ru.ifmo.ctddev.filippov.antlr.IOWriter;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class PascalParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.5.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		AND=1, ARRAY=2, BEGIN=3, BOOLEAN=4, CASE=5, CHAR=6, CHR=7, CONST=8, DIV=9, 
		DO=10, DOWNTO=11, ELSE=12, END=13, FILE=14, FOR=15, FUNCTION=16, GOTO=17, 
		IF=18, IN=19, INTEGER=20, LABEL=21, MOD=22, NIL=23, NOT=24, OF=25, OR=26, 
		PACKED=27, PROCEDURE=28, PROGRAM=29, REAL=30, RECORD=31, REPEAT=32, SET=33, 
		THEN=34, TO=35, TYPE=36, UNTIL=37, VAR=38, WHILE=39, WITH=40, PLUS=41, 
		MINUS=42, STAR=43, SLASH=44, ASSIGN=45, COMMA=46, SEMI=47, COLON=48, EQUAL=49, 
		NOT_EQUAL=50, LT=51, LE=52, GE=53, GT=54, LPAREN=55, RPAREN=56, LBRACK=57, 
		LBRACK2=58, RBRACK=59, RBRACK2=60, POINTER=61, AT=62, DOT=63, DOTDOT=64, 
		LCURLY=65, RCURLY=66, UNIT=67, INTERFACE=68, USES=69, STRING=70, IMPLEMENTATION=71, 
		WS=72, COMMENT_1=73, COMMENT_2=74, IDENT=75, STRING_LITERAL=76, NUM_INT=77;
	public static final int
		RULE_eval = 0, RULE_programStart = 1, RULE_identifier = 2, RULE_block = 3, 
		RULE_usesUnitsPart = 4, RULE_label = 5, RULE_constantDefinitionPart = 6, 
		RULE_constantDefinition = 7, RULE_constantChr = 8, RULE_constant = 9, 
		RULE_unsignedNumber = 10, RULE_unsignedInteger = 11, RULE_unsignedReal = 12, 
		RULE_sign = 13, RULE_string = 14, RULE_typeDefinitionPart = 15, RULE_typeDefinition = 16, 
		RULE_functionType = 17, RULE_procedureType = 18, RULE_type = 19, RULE_simpleType = 20, 
		RULE_scalarType = 21, RULE_subrangeType = 22, RULE_typeIdentifier = 23, 
		RULE_structuredType = 24, RULE_unpackedStructuredType = 25, RULE_stringtype = 26, 
		RULE_arrayType = 27, RULE_recordType = 28, RULE_fieldList = 29, RULE_fixedPart = 30, 
		RULE_recordSection = 31, RULE_variantPart = 32, RULE_tag = 33, RULE_variant = 34, 
		RULE_setType = 35, RULE_baseType = 36, RULE_fileType = 37, RULE_pointerType = 38, 
		RULE_variableDeclarationPart = 39, RULE_variableDeclaration = 40, RULE_procedureAndFunctionDeclarationPart = 41, 
		RULE_procedureDeclaration = 42, RULE_functionDeclaration = 43, RULE_formalParameterList = 44, 
		RULE_formalParameterSection = 45, RULE_parameterGroup = 46, RULE_identifierList = 47, 
		RULE_constList = 48, RULE_resultType = 49, RULE_statement = 50, RULE_unlabelledStatement = 51, 
		RULE_simpleStatement = 52, RULE_assignmentStatement = 53, RULE_variable = 54, 
		RULE_expression = 55, RULE_simpleExpression = 56, RULE_term = 57, RULE_signedFactor = 58, 
		RULE_factor = 59, RULE_unsignedConstant = 60, RULE_functionDesignator = 61, 
		RULE_parameterList = 62, RULE_set = 63, RULE_elementList = 64, RULE_element = 65, 
		RULE_procedureStatement = 66, RULE_actualParameter = 67, RULE_gotoStatement = 68, 
		RULE_emptyStatement = 69, RULE_empty = 70, RULE_structuredStatement = 71, 
		RULE_compoundStatement = 72, RULE_statements = 73, RULE_conditionalStatement = 74, 
		RULE_ifStatement = 75, RULE_caseStatement = 76, RULE_caseListElement = 77, 
		RULE_repetetiveStatement = 78, RULE_whileStatement = 79, RULE_repeatStatement = 80, 
		RULE_forStatement = 81, RULE_withStatement = 82, RULE_recordVariableList = 83;
	public static final String[] ruleNames = {
		"eval", "programStart", "identifier", "block", "usesUnitsPart", "label", 
		"constantDefinitionPart", "constantDefinition", "constantChr", "constant", 
		"unsignedNumber", "unsignedInteger", "unsignedReal", "sign", "string", 
		"typeDefinitionPart", "typeDefinition", "functionType", "procedureType", 
		"type", "simpleType", "scalarType", "subrangeType", "typeIdentifier", 
		"structuredType", "unpackedStructuredType", "stringtype", "arrayType", 
		"recordType", "fieldList", "fixedPart", "recordSection", "variantPart", 
		"tag", "variant", "setType", "baseType", "fileType", "pointerType", "variableDeclarationPart", 
		"variableDeclaration", "procedureAndFunctionDeclarationPart", "procedureDeclaration", 
		"functionDeclaration", "formalParameterList", "formalParameterSection", 
		"parameterGroup", "identifierList", "constList", "resultType", "statement", 
		"unlabelledStatement", "simpleStatement", "assignmentStatement", "variable", 
		"expression", "simpleExpression", "term", "signedFactor", "factor", "unsignedConstant", 
		"functionDesignator", "parameterList", "set", "elementList", "element", 
		"procedureStatement", "actualParameter", "gotoStatement", "emptyStatement", 
		"empty", "structuredStatement", "compoundStatement", "statements", "conditionalStatement", 
		"ifStatement", "caseStatement", "caseListElement", "repetetiveStatement", 
		"whileStatement", "repeatStatement", "forStatement", "withStatement", 
		"recordVariableList"
	};

	private static final String[] _LITERAL_NAMES = {
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, null, null, null, "'+'", "'-'", "'*'", "'/'", "':='", "','", 
		"';'", "':'", "'='", "'<>'", "'<'", "'<='", "'>='", "'>'", "'('", "')'", 
		"'['", "'(.'", "']'", "'.)'", "'^'", "'@'", "'.'", "'..'", "'{'", "'}'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "AND", "ARRAY", "BEGIN", "BOOLEAN", "CASE", "CHAR", "CHR", "CONST", 
		"DIV", "DO", "DOWNTO", "ELSE", "END", "FILE", "FOR", "FUNCTION", "GOTO", 
		"IF", "IN", "INTEGER", "LABEL", "MOD", "NIL", "NOT", "OF", "OR", "PACKED", 
		"PROCEDURE", "PROGRAM", "REAL", "RECORD", "REPEAT", "SET", "THEN", "TO", 
		"TYPE", "UNTIL", "VAR", "WHILE", "WITH", "PLUS", "MINUS", "STAR", "SLASH", 
		"ASSIGN", "COMMA", "SEMI", "COLON", "EQUAL", "NOT_EQUAL", "LT", "LE", 
		"GE", "GT", "LPAREN", "RPAREN", "LBRACK", "LBRACK2", "RBRACK", "RBRACK2", 
		"POINTER", "AT", "DOT", "DOTDOT", "LCURLY", "RCURLY", "UNIT", "INTERFACE", 
		"USES", "STRING", "IMPLEMENTATION", "WS", "COMMENT_1", "COMMENT_2", "IDENT", 
		"STRING_LITERAL", "NUM_INT"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Pascal.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


	    private static String addNewline(String s) {
	        if (s == null) {
	            return "";
	        }
	        if (s.equals("\n")) {
	            return "";
	        }
	        return s + "\n";
	    }
	        
	    String indent = "";

	    void updateIndent() {
	        indent = indent.isEmpty() ? "" : indent.substring(2);
	    }

	    void addLeft() {
	        indent = "  " + indent;
	    }

	    String printWithIndent(String s) {
	        if (!s.contains("\n")) {
	            return indent + s;
	        }
	        String splitted[] = s.split("\n");
	        StringBuilder sb = new StringBuilder();
	        for (String ns : splitted) {
	            if (!ns.isEmpty()) {
	                sb.append(indent).append(ns).append("\n");
	            }
	        }
	        sb.setLength(sb.length() - 1);
	        return sb.toString();
	    }

	public PascalParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class EvalContext extends ParserRuleContext {
		public String code;
		public BlockContext block;
		public ProgramStartContext programStart() {
			return getRuleContext(ProgramStartContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode DOT() { return getToken(PascalParser.DOT, 0); }
		public TerminalNode INTERFACE() { return getToken(PascalParser.INTERFACE, 0); }
		public EvalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_eval; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterEval(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitEval(this);
		}
	}

	public final EvalContext eval() throws RecognitionException {
		EvalContext _localctx = new EvalContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_eval);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(168);
			programStart();
			setState(170);
			_la = _input.LA(1);
			if (_la==INTERFACE) {
				{
				setState(169);
				match(INTERFACE);
				}
			}

			setState(172);
			((EvalContext)_localctx).block = block();
			setState(173);
			match(DOT);

			        ((EvalContext)_localctx).code =  "#include <bits/stdc++.h>\n\n";
			        _localctx.code += addNewline(((EvalContext)_localctx).block.variables);
			        for (String s : ((EvalContext)_localctx).block.functions) {
			            _localctx.code += addNewline(s);
			        }
			        _localctx.code += addNewline("int main() {");
			        _localctx.code += addNewline(((EvalContext)_localctx).block.mainFunctionCode);
			        _localctx.code += addNewline("  return 0;");
			        _localctx.code += addNewline("}");
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProgramStartContext extends ParserRuleContext {
		public TerminalNode PROGRAM() { return getToken(PascalParser.PROGRAM, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(PascalParser.SEMI, 0); }
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public TerminalNode UNIT() { return getToken(PascalParser.UNIT, 0); }
		public ProgramStartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_programStart; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterProgramStart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitProgramStart(this);
		}
	}

	public final ProgramStartContext programStart() throws RecognitionException {
		ProgramStartContext _localctx = new ProgramStartContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_programStart);
		int _la;
		try {
			setState(190);
			switch (_input.LA(1)) {
			case PROGRAM:
				enterOuterAlt(_localctx, 1);
				{
				setState(176);
				match(PROGRAM);
				setState(177);
				identifier();
				setState(182);
				_la = _input.LA(1);
				if (_la==LPAREN) {
					{
					setState(178);
					match(LPAREN);
					setState(179);
					identifierList();
					setState(180);
					match(RPAREN);
					}
				}

				setState(184);
				match(SEMI);
				}
				break;
			case UNIT:
				enterOuterAlt(_localctx, 2);
				{
				setState(186);
				match(UNIT);
				setState(187);
				identifier();
				setState(188);
				match(SEMI);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdentifierContext extends ParserRuleContext {
		public TerminalNode IDENT() { return getToken(PascalParser.IDENT, 0); }
		public IdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifier; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterIdentifier(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitIdentifier(this);
		}
	}

	public final IdentifierContext identifier() throws RecognitionException {
		IdentifierContext _localctx = new IdentifierContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_identifier);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(192);
			match(IDENT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public String variables =  "";
		public List<String> functions =  new ArrayList<String>();
		public String mainFunctionCode =  "";
		public HashMap<String, String> typesValues =  new HashMap<String,String>();
		public ConstantDefinitionPartContext constantDefinitionPart;
		public VariableDeclarationPartContext variableDeclarationPart;
		public ProcedureAndFunctionDeclarationPartContext procedureAndFunctionDeclarationPart;
		public CompoundStatementContext compoundStatement;
		public CompoundStatementContext compoundStatement() {
			return getRuleContext(CompoundStatementContext.class,0);
		}
		public List<ConstantDefinitionPartContext> constantDefinitionPart() {
			return getRuleContexts(ConstantDefinitionPartContext.class);
		}
		public ConstantDefinitionPartContext constantDefinitionPart(int i) {
			return getRuleContext(ConstantDefinitionPartContext.class,i);
		}
		public List<TypeDefinitionPartContext> typeDefinitionPart() {
			return getRuleContexts(TypeDefinitionPartContext.class);
		}
		public TypeDefinitionPartContext typeDefinitionPart(int i) {
			return getRuleContext(TypeDefinitionPartContext.class,i);
		}
		public List<VariableDeclarationPartContext> variableDeclarationPart() {
			return getRuleContexts(VariableDeclarationPartContext.class);
		}
		public VariableDeclarationPartContext variableDeclarationPart(int i) {
			return getRuleContext(VariableDeclarationPartContext.class,i);
		}
		public List<ProcedureAndFunctionDeclarationPartContext> procedureAndFunctionDeclarationPart() {
			return getRuleContexts(ProcedureAndFunctionDeclarationPartContext.class);
		}
		public ProcedureAndFunctionDeclarationPartContext procedureAndFunctionDeclarationPart(int i) {
			return getRuleContext(ProcedureAndFunctionDeclarationPartContext.class,i);
		}
		public List<UsesUnitsPartContext> usesUnitsPart() {
			return getRuleContexts(UsesUnitsPartContext.class);
		}
		public UsesUnitsPartContext usesUnitsPart(int i) {
			return getRuleContext(UsesUnitsPartContext.class,i);
		}
		public List<TerminalNode> IMPLEMENTATION() { return getTokens(PascalParser.IMPLEMENTATION); }
		public TerminalNode IMPLEMENTATION(int i) {
			return getToken(PascalParser.IMPLEMENTATION, i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitBlock(this);
		}
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(208);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 8)) & ~0x3f) == 0 && ((1L << (_la - 8)) & ((1L << (CONST - 8)) | (1L << (FUNCTION - 8)) | (1L << (PROCEDURE - 8)) | (1L << (TYPE - 8)) | (1L << (VAR - 8)) | (1L << (USES - 8)) | (1L << (IMPLEMENTATION - 8)))) != 0)) {
				{
				setState(206);
				switch (_input.LA(1)) {
				case CONST:
					{
					setState(194);
					((BlockContext)_localctx).constantDefinitionPart = constantDefinitionPart();
					 _localctx.variables += ((BlockContext)_localctx).constantDefinitionPart.code + "\n"; 
					}
					break;
				case TYPE:
					{
					setState(197);
					typeDefinitionPart();
					}
					break;
				case VAR:
					{
					setState(198);
					((BlockContext)_localctx).variableDeclarationPart = variableDeclarationPart();
					 _localctx.variables += ((BlockContext)_localctx).variableDeclarationPart.code + "\n"; 
					}
					break;
				case FUNCTION:
				case PROCEDURE:
					{
					setState(201);
					((BlockContext)_localctx).procedureAndFunctionDeclarationPart = procedureAndFunctionDeclarationPart();
					_localctx.functions.add(((BlockContext)_localctx).procedureAndFunctionDeclarationPart.code);
					}
					break;
				case USES:
					{
					setState(204);
					usesUnitsPart();
					}
					break;
				case IMPLEMENTATION:
					{
					setState(205);
					match(IMPLEMENTATION);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(210);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			 addLeft(); 
			setState(212);
			((BlockContext)_localctx).compoundStatement = compoundStatement();
			 updateIndent(); 
			((BlockContext)_localctx).mainFunctionCode =  ((BlockContext)_localctx).compoundStatement.code;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UsesUnitsPartContext extends ParserRuleContext {
		public TerminalNode USES() { return getToken(PascalParser.USES, 0); }
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(PascalParser.SEMI, 0); }
		public UsesUnitsPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_usesUnitsPart; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterUsesUnitsPart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitUsesUnitsPart(this);
		}
	}

	public final UsesUnitsPartContext usesUnitsPart() throws RecognitionException {
		UsesUnitsPartContext _localctx = new UsesUnitsPartContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_usesUnitsPart);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(216);
			match(USES);
			setState(217);
			identifierList();
			setState(218);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LabelContext extends ParserRuleContext {
		public UnsignedIntegerContext unsignedInteger() {
			return getRuleContext(UnsignedIntegerContext.class,0);
		}
		public LabelContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_label; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterLabel(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitLabel(this);
		}
	}

	public final LabelContext label() throws RecognitionException {
		LabelContext _localctx = new LabelContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_label);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(220);
			unsignedInteger();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantDefinitionPartContext extends ParserRuleContext {
		public String code;
		public ConstantDefinitionContext constantDefinition;
		public TerminalNode CONST() { return getToken(PascalParser.CONST, 0); }
		public List<ConstantDefinitionContext> constantDefinition() {
			return getRuleContexts(ConstantDefinitionContext.class);
		}
		public ConstantDefinitionContext constantDefinition(int i) {
			return getRuleContext(ConstantDefinitionContext.class,i);
		}
		public List<TerminalNode> SEMI() { return getTokens(PascalParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(PascalParser.SEMI, i);
		}
		public ConstantDefinitionPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constantDefinitionPart; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterConstantDefinitionPart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitConstantDefinitionPart(this);
		}
	}

	public final ConstantDefinitionPartContext constantDefinitionPart() throws RecognitionException {
		ConstantDefinitionPartContext _localctx = new ConstantDefinitionPartContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_constantDefinitionPart);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(222);
			match(CONST);
			setState(223);
			((ConstantDefinitionPartContext)_localctx).constantDefinition = constantDefinition();
			((ConstantDefinitionPartContext)_localctx).code =  ((ConstantDefinitionPartContext)_localctx).constantDefinition.code;
			setState(231);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(225);
					match(SEMI);
					setState(226);
					((ConstantDefinitionPartContext)_localctx).constantDefinition = constantDefinition();
					_localctx.code += "\n" + ((ConstantDefinitionPartContext)_localctx).constantDefinition.code;
					}
					} 
				}
				setState(233);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			}
			setState(234);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantDefinitionContext extends ParserRuleContext {
		public String code;
		public IdentifierContext identifier;
		public ConstantContext constant;
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode EQUAL() { return getToken(PascalParser.EQUAL, 0); }
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public ConstantDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constantDefinition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterConstantDefinition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitConstantDefinition(this);
		}
	}

	public final ConstantDefinitionContext constantDefinition() throws RecognitionException {
		ConstantDefinitionContext _localctx = new ConstantDefinitionContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_constantDefinition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(236);
			((ConstantDefinitionContext)_localctx).identifier = identifier();
			setState(237);
			match(EQUAL);
			setState(238);
			((ConstantDefinitionContext)_localctx).constant = constant();
			((ConstantDefinitionContext)_localctx).code =  "const " + (((ConstantDefinitionContext)_localctx).identifier!=null?_input.getText(((ConstantDefinitionContext)_localctx).identifier.start,((ConstantDefinitionContext)_localctx).identifier.stop):null) + " = " + ((ConstantDefinitionContext)_localctx).constant.code + ";";
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantChrContext extends ParserRuleContext {
		public TerminalNode CHR() { return getToken(PascalParser.CHR, 0); }
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public UnsignedIntegerContext unsignedInteger() {
			return getRuleContext(UnsignedIntegerContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public ConstantChrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constantChr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterConstantChr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitConstantChr(this);
		}
	}

	public final ConstantChrContext constantChr() throws RecognitionException {
		ConstantChrContext _localctx = new ConstantChrContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_constantChr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(241);
			match(CHR);
			setState(242);
			match(LPAREN);
			setState(243);
			unsignedInteger();
			setState(244);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantContext extends ParserRuleContext {
		public String code;
		public UnsignedNumberContext unsignedNumber;
		public SignContext sign;
		public IdentifierContext identifier;
		public StringContext string;
		public UnsignedNumberContext unsignedNumber() {
			return getRuleContext(UnsignedNumberContext.class,0);
		}
		public SignContext sign() {
			return getRuleContext(SignContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public StringContext string() {
			return getRuleContext(StringContext.class,0);
		}
		public ConstantChrContext constantChr() {
			return getRuleContext(ConstantChrContext.class,0);
		}
		public ConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterConstant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitConstant(this);
		}
	}

	public final ConstantContext constant() throws RecognitionException {
		ConstantContext _localctx = new ConstantContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_constant);
		try {
			setState(264);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(246);
				((ConstantContext)_localctx).unsignedNumber = unsignedNumber();
				((ConstantContext)_localctx).code =  (((ConstantContext)_localctx).unsignedNumber!=null?_input.getText(((ConstantContext)_localctx).unsignedNumber.start,((ConstantContext)_localctx).unsignedNumber.stop):null);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(249);
				((ConstantContext)_localctx).sign = sign();
				setState(250);
				((ConstantContext)_localctx).unsignedNumber = unsignedNumber();
				((ConstantContext)_localctx).code =  (((ConstantContext)_localctx).sign!=null?_input.getText(((ConstantContext)_localctx).sign.start,((ConstantContext)_localctx).sign.stop):null) + (((ConstantContext)_localctx).unsignedNumber!=null?_input.getText(((ConstantContext)_localctx).unsignedNumber.start,((ConstantContext)_localctx).unsignedNumber.stop):null);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(253);
				((ConstantContext)_localctx).identifier = identifier();
				((ConstantContext)_localctx).code =  (((ConstantContext)_localctx).identifier!=null?_input.getText(((ConstantContext)_localctx).identifier.start,((ConstantContext)_localctx).identifier.stop):null);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(256);
				((ConstantContext)_localctx).sign = sign();
				setState(257);
				((ConstantContext)_localctx).identifier = identifier();
				((ConstantContext)_localctx).code =  (((ConstantContext)_localctx).sign!=null?_input.getText(((ConstantContext)_localctx).sign.start,((ConstantContext)_localctx).sign.stop):null) + (((ConstantContext)_localctx).identifier!=null?_input.getText(((ConstantContext)_localctx).identifier.start,((ConstantContext)_localctx).identifier.stop):null);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(260);
				((ConstantContext)_localctx).string = string();
				((ConstantContext)_localctx).code =  ((ConstantContext)_localctx).string.code;
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(263);
				constantChr();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnsignedNumberContext extends ParserRuleContext {
		public UnsignedIntegerContext unsignedInteger() {
			return getRuleContext(UnsignedIntegerContext.class,0);
		}
		public UnsignedRealContext unsignedReal() {
			return getRuleContext(UnsignedRealContext.class,0);
		}
		public UnsignedNumberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsignedNumber; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterUnsignedNumber(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitUnsignedNumber(this);
		}
	}

	public final UnsignedNumberContext unsignedNumber() throws RecognitionException {
		UnsignedNumberContext _localctx = new UnsignedNumberContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_unsignedNumber);
		try {
			setState(268);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(266);
				unsignedInteger();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(267);
				unsignedReal();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnsignedIntegerContext extends ParserRuleContext {
		public TerminalNode NUM_INT() { return getToken(PascalParser.NUM_INT, 0); }
		public UnsignedIntegerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsignedInteger; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterUnsignedInteger(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitUnsignedInteger(this);
		}
	}

	public final UnsignedIntegerContext unsignedInteger() throws RecognitionException {
		UnsignedIntegerContext _localctx = new UnsignedIntegerContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_unsignedInteger);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(270);
			match(NUM_INT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnsignedRealContext extends ParserRuleContext {
		public TerminalNode NUM_INT() { return getToken(PascalParser.NUM_INT, 0); }
		public UnsignedRealContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsignedReal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterUnsignedReal(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitUnsignedReal(this);
		}
	}

	public final UnsignedRealContext unsignedReal() throws RecognitionException {
		UnsignedRealContext _localctx = new UnsignedRealContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_unsignedReal);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(272);
			match(NUM_INT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SignContext extends ParserRuleContext {
		public TerminalNode PLUS() { return getToken(PascalParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(PascalParser.MINUS, 0); }
		public SignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sign; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterSign(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitSign(this);
		}
	}

	public final SignContext sign() throws RecognitionException {
		SignContext _localctx = new SignContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_sign);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(274);
			_la = _input.LA(1);
			if ( !(_la==PLUS || _la==MINUS) ) {
			_errHandler.recoverInline(this);
			} else {
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringContext extends ParserRuleContext {
		public String code;
		public Token STRING_LITERAL;
		public TerminalNode STRING_LITERAL() { return getToken(PascalParser.STRING_LITERAL, 0); }
		public StringContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_string; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterString(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitString(this);
		}
	}

	public final StringContext string() throws RecognitionException {
		StringContext _localctx = new StringContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_string);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(276);
			((StringContext)_localctx).STRING_LITERAL = match(STRING_LITERAL);

			        String t = (((StringContext)_localctx).STRING_LITERAL!=null?((StringContext)_localctx).STRING_LITERAL.getText():null);
			        ((StringContext)_localctx).code =  "\"" + t.substring(1, t.length() - 1) + "\"";
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeDefinitionPartContext extends ParserRuleContext {
		public TerminalNode TYPE() { return getToken(PascalParser.TYPE, 0); }
		public List<TypeDefinitionContext> typeDefinition() {
			return getRuleContexts(TypeDefinitionContext.class);
		}
		public TypeDefinitionContext typeDefinition(int i) {
			return getRuleContext(TypeDefinitionContext.class,i);
		}
		public List<TerminalNode> SEMI() { return getTokens(PascalParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(PascalParser.SEMI, i);
		}
		public TypeDefinitionPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeDefinitionPart; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterTypeDefinitionPart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitTypeDefinitionPart(this);
		}
	}

	public final TypeDefinitionPartContext typeDefinitionPart() throws RecognitionException {
		TypeDefinitionPartContext _localctx = new TypeDefinitionPartContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_typeDefinitionPart);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(279);
			match(TYPE);
			setState(280);
			typeDefinition();
			setState(285);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(281);
					match(SEMI);
					setState(282);
					typeDefinition();
					}
					} 
				}
				setState(287);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			}
			setState(288);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeDefinitionContext extends ParserRuleContext {
		public IdentifierContext identifier;
		public TypeContext type;
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode EQUAL() { return getToken(PascalParser.EQUAL, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public FunctionTypeContext functionType() {
			return getRuleContext(FunctionTypeContext.class,0);
		}
		public ProcedureTypeContext procedureType() {
			return getRuleContext(ProcedureTypeContext.class,0);
		}
		public TypeDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeDefinition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterTypeDefinition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitTypeDefinition(this);
		}
	}

	public final TypeDefinitionContext typeDefinition() throws RecognitionException {
		TypeDefinitionContext _localctx = new TypeDefinitionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_typeDefinition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(290);
			((TypeDefinitionContext)_localctx).identifier = identifier();
			setState(291);
			match(EQUAL);
			setState(297);
			switch (_input.LA(1)) {
			case ARRAY:
			case BOOLEAN:
			case CHAR:
			case CHR:
			case FILE:
			case INTEGER:
			case PACKED:
			case REAL:
			case RECORD:
			case SET:
			case PLUS:
			case MINUS:
			case LPAREN:
			case POINTER:
			case STRING:
			case IDENT:
			case STRING_LITERAL:
			case NUM_INT:
				{
				setState(292);
				((TypeDefinitionContext)_localctx).type = type();
				((BlockContext)getInvokingContext(3)).typesValues.put((((TypeDefinitionContext)_localctx).identifier!=null?_input.getText(((TypeDefinitionContext)_localctx).identifier.start,((TypeDefinitionContext)_localctx).identifier.stop):null), ((TypeDefinitionContext)_localctx).type.code);
				}
				break;
			case FUNCTION:
				{
				setState(295);
				functionType();
				}
				break;
			case PROCEDURE:
				{
				setState(296);
				procedureType();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionTypeContext extends ParserRuleContext {
		public TerminalNode FUNCTION() { return getToken(PascalParser.FUNCTION, 0); }
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public ResultTypeContext resultType() {
			return getRuleContext(ResultTypeContext.class,0);
		}
		public FormalParameterListContext formalParameterList() {
			return getRuleContext(FormalParameterListContext.class,0);
		}
		public FunctionTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterFunctionType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitFunctionType(this);
		}
	}

	public final FunctionTypeContext functionType() throws RecognitionException {
		FunctionTypeContext _localctx = new FunctionTypeContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_functionType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(299);
			match(FUNCTION);
			setState(301);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(300);
				formalParameterList();
				}
			}

			setState(303);
			match(COLON);
			setState(304);
			resultType();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcedureTypeContext extends ParserRuleContext {
		public TerminalNode PROCEDURE() { return getToken(PascalParser.PROCEDURE, 0); }
		public FormalParameterListContext formalParameterList() {
			return getRuleContext(FormalParameterListContext.class,0);
		}
		public ProcedureTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procedureType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterProcedureType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitProcedureType(this);
		}
	}

	public final ProcedureTypeContext procedureType() throws RecognitionException {
		ProcedureTypeContext _localctx = new ProcedureTypeContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_procedureType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(306);
			match(PROCEDURE);
			setState(308);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(307);
				formalParameterList();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeContext extends ParserRuleContext {
		public String code;
		public SimpleTypeContext simpleType;
		public StructuredTypeContext structuredType;
		public PointerTypeContext pointerType;
		public SimpleTypeContext simpleType() {
			return getRuleContext(SimpleTypeContext.class,0);
		}
		public StructuredTypeContext structuredType() {
			return getRuleContext(StructuredTypeContext.class,0);
		}
		public PointerTypeContext pointerType() {
			return getRuleContext(PointerTypeContext.class,0);
		}
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitType(this);
		}
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_type);
		try {
			setState(319);
			switch (_input.LA(1)) {
			case BOOLEAN:
			case CHAR:
			case CHR:
			case INTEGER:
			case REAL:
			case PLUS:
			case MINUS:
			case LPAREN:
			case STRING:
			case IDENT:
			case STRING_LITERAL:
			case NUM_INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(310);
				((TypeContext)_localctx).simpleType = simpleType();
				((TypeContext)_localctx).code =  ((TypeContext)_localctx).simpleType.code;
				}
				break;
			case ARRAY:
			case FILE:
			case PACKED:
			case RECORD:
			case SET:
				enterOuterAlt(_localctx, 2);
				{
				setState(313);
				((TypeContext)_localctx).structuredType = structuredType();
				((TypeContext)_localctx).code =  ((TypeContext)_localctx).structuredType.code;
				}
				break;
			case POINTER:
				enterOuterAlt(_localctx, 3);
				{
				setState(316);
				((TypeContext)_localctx).pointerType = pointerType();
				((TypeContext)_localctx).code =  (((TypeContext)_localctx).pointerType!=null?_input.getText(((TypeContext)_localctx).pointerType.start,((TypeContext)_localctx).pointerType.stop):null);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SimpleTypeContext extends ParserRuleContext {
		public String code;
		public TypeIdentifierContext typeIdentifier;
		public SubrangeTypeContext subrangeType;
		public TypeIdentifierContext typeIdentifier() {
			return getRuleContext(TypeIdentifierContext.class,0);
		}
		public SubrangeTypeContext subrangeType() {
			return getRuleContext(SubrangeTypeContext.class,0);
		}
		public ScalarTypeContext scalarType() {
			return getRuleContext(ScalarTypeContext.class,0);
		}
		public StringtypeContext stringtype() {
			return getRuleContext(StringtypeContext.class,0);
		}
		public SimpleTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterSimpleType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitSimpleType(this);
		}
	}

	public final SimpleTypeContext simpleType() throws RecognitionException {
		SimpleTypeContext _localctx = new SimpleTypeContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_simpleType);
		try {
			setState(331);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(321);
				((SimpleTypeContext)_localctx).typeIdentifier = typeIdentifier();
				((SimpleTypeContext)_localctx).code =  ((SimpleTypeContext)_localctx).typeIdentifier.code;
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(324);
				((SimpleTypeContext)_localctx).subrangeType = subrangeType();
				((SimpleTypeContext)_localctx).code =  ((SimpleTypeContext)_localctx).subrangeType.upperBound;
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(327);
				scalarType();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(328);
				stringtype();
				((SimpleTypeContext)_localctx).code =  "std::string";
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ScalarTypeContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public ScalarTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scalarType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterScalarType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitScalarType(this);
		}
	}

	public final ScalarTypeContext scalarType() throws RecognitionException {
		ScalarTypeContext _localctx = new ScalarTypeContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_scalarType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(333);
			match(LPAREN);
			setState(334);
			identifierList();
			setState(335);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SubrangeTypeContext extends ParserRuleContext {
		public String upperBound;
		public ConstantContext constant;
		public List<ConstantContext> constant() {
			return getRuleContexts(ConstantContext.class);
		}
		public ConstantContext constant(int i) {
			return getRuleContext(ConstantContext.class,i);
		}
		public TerminalNode DOTDOT() { return getToken(PascalParser.DOTDOT, 0); }
		public SubrangeTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_subrangeType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterSubrangeType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitSubrangeType(this);
		}
	}

	public final SubrangeTypeContext subrangeType() throws RecognitionException {
		SubrangeTypeContext _localctx = new SubrangeTypeContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_subrangeType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(337);
			((SubrangeTypeContext)_localctx).constant = constant();
			setState(338);
			match(DOTDOT);
			setState(339);
			((SubrangeTypeContext)_localctx).constant = constant();
			((SubrangeTypeContext)_localctx).upperBound =  ((SubrangeTypeContext)_localctx).constant.code;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeIdentifierContext extends ParserRuleContext {
		public String code;
		public IdentifierContext identifier;
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode CHAR() { return getToken(PascalParser.CHAR, 0); }
		public TerminalNode BOOLEAN() { return getToken(PascalParser.BOOLEAN, 0); }
		public TerminalNode INTEGER() { return getToken(PascalParser.INTEGER, 0); }
		public TerminalNode REAL() { return getToken(PascalParser.REAL, 0); }
		public TerminalNode STRING() { return getToken(PascalParser.STRING, 0); }
		public TypeIdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeIdentifier; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterTypeIdentifier(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitTypeIdentifier(this);
		}
	}

	public final TypeIdentifierContext typeIdentifier() throws RecognitionException {
		TypeIdentifierContext _localctx = new TypeIdentifierContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_typeIdentifier);
		try {
			setState(357);
			switch (_input.LA(1)) {
			case IDENT:
				enterOuterAlt(_localctx, 1);
				{
				setState(342);
				((TypeIdentifierContext)_localctx).identifier = identifier();

				        ((TypeIdentifierContext)_localctx).code =  ((BlockContext)getInvokingContext(3)).typesValues.get((((TypeIdentifierContext)_localctx).identifier!=null?_input.getText(((TypeIdentifierContext)_localctx).identifier.start,((TypeIdentifierContext)_localctx).identifier.stop):null));
				        if (_localctx.code == null) {
				            ((TypeIdentifierContext)_localctx).code =  (((TypeIdentifierContext)_localctx).identifier!=null?_input.getText(((TypeIdentifierContext)_localctx).identifier.start,((TypeIdentifierContext)_localctx).identifier.stop):null);
				        }
				    
				}
				break;
			case BOOLEAN:
			case CHAR:
			case INTEGER:
			case REAL:
			case STRING:
				enterOuterAlt(_localctx, 2);
				{
				setState(355);
				switch (_input.LA(1)) {
				case CHAR:
					{
					setState(345);
					match(CHAR);
					((TypeIdentifierContext)_localctx).code =  "char";
					}
					break;
				case BOOLEAN:
					{
					setState(347);
					match(BOOLEAN);
					((TypeIdentifierContext)_localctx).code =  "bool";
					}
					break;
				case INTEGER:
					{
					setState(349);
					match(INTEGER);
					((TypeIdentifierContext)_localctx).code =  "int";
					}
					break;
				case REAL:
					{
					setState(351);
					match(REAL);
					((TypeIdentifierContext)_localctx).code =  "double";
					}
					break;
				case STRING:
					{
					setState(353);
					match(STRING);
					((TypeIdentifierContext)_localctx).code =  "std::string";
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StructuredTypeContext extends ParserRuleContext {
		public String code;
		public UnpackedStructuredTypeContext unpackedStructuredType;
		public TerminalNode PACKED() { return getToken(PascalParser.PACKED, 0); }
		public UnpackedStructuredTypeContext unpackedStructuredType() {
			return getRuleContext(UnpackedStructuredTypeContext.class,0);
		}
		public StructuredTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_structuredType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterStructuredType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitStructuredType(this);
		}
	}

	public final StructuredTypeContext structuredType() throws RecognitionException {
		StructuredTypeContext _localctx = new StructuredTypeContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_structuredType);
		try {
			setState(364);
			switch (_input.LA(1)) {
			case PACKED:
				enterOuterAlt(_localctx, 1);
				{
				setState(359);
				match(PACKED);
				setState(360);
				unpackedStructuredType();
				}
				break;
			case ARRAY:
			case FILE:
			case RECORD:
			case SET:
				enterOuterAlt(_localctx, 2);
				{
				setState(361);
				((StructuredTypeContext)_localctx).unpackedStructuredType = unpackedStructuredType();
				((StructuredTypeContext)_localctx).code =  ((StructuredTypeContext)_localctx).unpackedStructuredType.code;
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnpackedStructuredTypeContext extends ParserRuleContext {
		public String code;
		public ArrayTypeContext arrayType;
		public ArrayTypeContext arrayType() {
			return getRuleContext(ArrayTypeContext.class,0);
		}
		public RecordTypeContext recordType() {
			return getRuleContext(RecordTypeContext.class,0);
		}
		public SetTypeContext setType() {
			return getRuleContext(SetTypeContext.class,0);
		}
		public FileTypeContext fileType() {
			return getRuleContext(FileTypeContext.class,0);
		}
		public UnpackedStructuredTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unpackedStructuredType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterUnpackedStructuredType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitUnpackedStructuredType(this);
		}
	}

	public final UnpackedStructuredTypeContext unpackedStructuredType() throws RecognitionException {
		UnpackedStructuredTypeContext _localctx = new UnpackedStructuredTypeContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_unpackedStructuredType);
		try {
			setState(372);
			switch (_input.LA(1)) {
			case ARRAY:
				enterOuterAlt(_localctx, 1);
				{
				setState(366);
				((UnpackedStructuredTypeContext)_localctx).arrayType = arrayType();
				((UnpackedStructuredTypeContext)_localctx).code =  "std::array<" + ((UnpackedStructuredTypeContext)_localctx).arrayType.elemType + ", " + ((UnpackedStructuredTypeContext)_localctx).arrayType.dimensions + ">";
				}
				break;
			case RECORD:
				enterOuterAlt(_localctx, 2);
				{
				setState(369);
				recordType();
				}
				break;
			case SET:
				enterOuterAlt(_localctx, 3);
				{
				setState(370);
				setType();
				}
				break;
			case FILE:
				enterOuterAlt(_localctx, 4);
				{
				setState(371);
				fileType();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringtypeContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(PascalParser.STRING, 0); }
		public TerminalNode LBRACK() { return getToken(PascalParser.LBRACK, 0); }
		public TerminalNode RBRACK() { return getToken(PascalParser.RBRACK, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public UnsignedNumberContext unsignedNumber() {
			return getRuleContext(UnsignedNumberContext.class,0);
		}
		public StringtypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stringtype; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterStringtype(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitStringtype(this);
		}
	}

	public final StringtypeContext stringtype() throws RecognitionException {
		StringtypeContext _localctx = new StringtypeContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_stringtype);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(374);
			match(STRING);
			setState(375);
			match(LBRACK);
			setState(378);
			switch (_input.LA(1)) {
			case IDENT:
				{
				setState(376);
				identifier();
				}
				break;
			case NUM_INT:
				{
				setState(377);
				unsignedNumber();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(380);
			match(RBRACK);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArrayTypeContext extends ParserRuleContext {
		public String elemType;
		public String dimensions;
		public SimpleTypeContext simpleType;
		public TypeContext type;
		public TerminalNode ARRAY() { return getToken(PascalParser.ARRAY, 0); }
		public TerminalNode LBRACK() { return getToken(PascalParser.LBRACK, 0); }
		public List<SimpleTypeContext> simpleType() {
			return getRuleContexts(SimpleTypeContext.class);
		}
		public SimpleTypeContext simpleType(int i) {
			return getRuleContext(SimpleTypeContext.class,i);
		}
		public TerminalNode RBRACK() { return getToken(PascalParser.RBRACK, 0); }
		public TerminalNode OF() { return getToken(PascalParser.OF, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public ArrayTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterArrayType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitArrayType(this);
		}
	}

	public final ArrayTypeContext arrayType() throws RecognitionException {
		ArrayTypeContext _localctx = new ArrayTypeContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_arrayType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(382);
			match(ARRAY);
			setState(383);
			match(LBRACK);
			setState(384);
			((ArrayTypeContext)_localctx).simpleType = simpleType();
			((ArrayTypeContext)_localctx).dimensions =  "(" + ((ArrayTypeContext)_localctx).simpleType.code + "+1)";
			setState(392);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(386);
				match(COMMA);
				setState(387);
				((ArrayTypeContext)_localctx).simpleType = simpleType();
				_localctx.dimensions += "(" + ((ArrayTypeContext)_localctx).simpleType.code + "+1)";
				}
				}
				setState(394);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(395);
			match(RBRACK);
			setState(396);
			match(OF);
			setState(397);
			((ArrayTypeContext)_localctx).type = type();
			((ArrayTypeContext)_localctx).elemType =  ((ArrayTypeContext)_localctx).type.code;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RecordTypeContext extends ParserRuleContext {
		public TerminalNode RECORD() { return getToken(PascalParser.RECORD, 0); }
		public FieldListContext fieldList() {
			return getRuleContext(FieldListContext.class,0);
		}
		public TerminalNode END() { return getToken(PascalParser.END, 0); }
		public RecordTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recordType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterRecordType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitRecordType(this);
		}
	}

	public final RecordTypeContext recordType() throws RecognitionException {
		RecordTypeContext _localctx = new RecordTypeContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_recordType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(400);
			match(RECORD);
			setState(401);
			fieldList();
			setState(402);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FieldListContext extends ParserRuleContext {
		public FixedPartContext fixedPart() {
			return getRuleContext(FixedPartContext.class,0);
		}
		public VariantPartContext variantPart() {
			return getRuleContext(VariantPartContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(PascalParser.SEMI, 0); }
		public FieldListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fieldList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterFieldList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitFieldList(this);
		}
	}

	public final FieldListContext fieldList() throws RecognitionException {
		FieldListContext _localctx = new FieldListContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_fieldList);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(411);
			switch (_input.LA(1)) {
			case IDENT:
				{
				setState(404);
				fixedPart();
				setState(408);
				switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
				case 1:
					{
					setState(405);
					match(SEMI);
					setState(406);
					variantPart();
					}
					break;
				case 2:
					{
					setState(407);
					match(SEMI);
					}
					break;
				}
				}
				break;
			case CASE:
				{
				setState(410);
				variantPart();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FixedPartContext extends ParserRuleContext {
		public List<RecordSectionContext> recordSection() {
			return getRuleContexts(RecordSectionContext.class);
		}
		public RecordSectionContext recordSection(int i) {
			return getRuleContext(RecordSectionContext.class,i);
		}
		public List<TerminalNode> SEMI() { return getTokens(PascalParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(PascalParser.SEMI, i);
		}
		public FixedPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fixedPart; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterFixedPart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitFixedPart(this);
		}
	}

	public final FixedPartContext fixedPart() throws RecognitionException {
		FixedPartContext _localctx = new FixedPartContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_fixedPart);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(413);
			recordSection();
			setState(418);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(414);
					match(SEMI);
					setState(415);
					recordSection();
					}
					} 
				}
				setState(420);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RecordSectionContext extends ParserRuleContext {
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public RecordSectionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recordSection; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterRecordSection(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitRecordSection(this);
		}
	}

	public final RecordSectionContext recordSection() throws RecognitionException {
		RecordSectionContext _localctx = new RecordSectionContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_recordSection);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(421);
			identifierList();
			setState(422);
			match(COLON);
			setState(423);
			type();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariantPartContext extends ParserRuleContext {
		public TerminalNode CASE() { return getToken(PascalParser.CASE, 0); }
		public TagContext tag() {
			return getRuleContext(TagContext.class,0);
		}
		public TerminalNode OF() { return getToken(PascalParser.OF, 0); }
		public List<VariantContext> variant() {
			return getRuleContexts(VariantContext.class);
		}
		public VariantContext variant(int i) {
			return getRuleContext(VariantContext.class,i);
		}
		public List<TerminalNode> SEMI() { return getTokens(PascalParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(PascalParser.SEMI, i);
		}
		public VariantPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variantPart; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterVariantPart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitVariantPart(this);
		}
	}

	public final VariantPartContext variantPart() throws RecognitionException {
		VariantPartContext _localctx = new VariantPartContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_variantPart);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(425);
			match(CASE);
			setState(426);
			tag();
			setState(427);
			match(OF);
			setState(428);
			variant();
			setState(434);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SEMI) {
				{
				setState(432);
				switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
				case 1:
					{
					setState(429);
					match(SEMI);
					setState(430);
					variant();
					}
					break;
				case 2:
					{
					setState(431);
					match(SEMI);
					}
					break;
				}
				}
				setState(436);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TagContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public TypeIdentifierContext typeIdentifier() {
			return getRuleContext(TypeIdentifierContext.class,0);
		}
		public TagContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_tag; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterTag(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitTag(this);
		}
	}

	public final TagContext tag() throws RecognitionException {
		TagContext _localctx = new TagContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_tag);
		try {
			setState(442);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(437);
				identifier();
				setState(438);
				match(COLON);
				setState(439);
				typeIdentifier();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(441);
				typeIdentifier();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariantContext extends ParserRuleContext {
		public ConstListContext constList() {
			return getRuleContext(ConstListContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public FieldListContext fieldList() {
			return getRuleContext(FieldListContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public VariantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variant; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterVariant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitVariant(this);
		}
	}

	public final VariantContext variant() throws RecognitionException {
		VariantContext _localctx = new VariantContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_variant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(444);
			constList();
			setState(445);
			match(COLON);
			setState(446);
			match(LPAREN);
			setState(447);
			fieldList();
			setState(448);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SetTypeContext extends ParserRuleContext {
		public TerminalNode SET() { return getToken(PascalParser.SET, 0); }
		public TerminalNode OF() { return getToken(PascalParser.OF, 0); }
		public BaseTypeContext baseType() {
			return getRuleContext(BaseTypeContext.class,0);
		}
		public SetTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_setType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterSetType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitSetType(this);
		}
	}

	public final SetTypeContext setType() throws RecognitionException {
		SetTypeContext _localctx = new SetTypeContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_setType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(450);
			match(SET);
			setState(451);
			match(OF);
			setState(452);
			baseType();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BaseTypeContext extends ParserRuleContext {
		public SimpleTypeContext simpleType() {
			return getRuleContext(SimpleTypeContext.class,0);
		}
		public BaseTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_baseType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterBaseType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitBaseType(this);
		}
	}

	public final BaseTypeContext baseType() throws RecognitionException {
		BaseTypeContext _localctx = new BaseTypeContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_baseType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(454);
			simpleType();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FileTypeContext extends ParserRuleContext {
		public TerminalNode FILE() { return getToken(PascalParser.FILE, 0); }
		public TerminalNode OF() { return getToken(PascalParser.OF, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public FileTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fileType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterFileType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitFileType(this);
		}
	}

	public final FileTypeContext fileType() throws RecognitionException {
		FileTypeContext _localctx = new FileTypeContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_fileType);
		try {
			setState(460);
			switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(456);
				match(FILE);
				setState(457);
				match(OF);
				setState(458);
				type();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(459);
				match(FILE);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PointerTypeContext extends ParserRuleContext {
		public TerminalNode POINTER() { return getToken(PascalParser.POINTER, 0); }
		public TypeIdentifierContext typeIdentifier() {
			return getRuleContext(TypeIdentifierContext.class,0);
		}
		public PointerTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pointerType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterPointerType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitPointerType(this);
		}
	}

	public final PointerTypeContext pointerType() throws RecognitionException {
		PointerTypeContext _localctx = new PointerTypeContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_pointerType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(462);
			match(POINTER);
			setState(463);
			typeIdentifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariableDeclarationPartContext extends ParserRuleContext {
		public String code;
		public VariableDeclarationContext variableDeclaration;
		public TerminalNode VAR() { return getToken(PascalParser.VAR, 0); }
		public List<VariableDeclarationContext> variableDeclaration() {
			return getRuleContexts(VariableDeclarationContext.class);
		}
		public VariableDeclarationContext variableDeclaration(int i) {
			return getRuleContext(VariableDeclarationContext.class,i);
		}
		public List<TerminalNode> SEMI() { return getTokens(PascalParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(PascalParser.SEMI, i);
		}
		public VariableDeclarationPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableDeclarationPart; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterVariableDeclarationPart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitVariableDeclarationPart(this);
		}
	}

	public final VariableDeclarationPartContext variableDeclarationPart() throws RecognitionException {
		VariableDeclarationPartContext _localctx = new VariableDeclarationPartContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_variableDeclarationPart);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(465);
			match(VAR);
			setState(466);
			((VariableDeclarationPartContext)_localctx).variableDeclaration = variableDeclaration();
			((VariableDeclarationPartContext)_localctx).code =  ((VariableDeclarationPartContext)_localctx).variableDeclaration.code;
			setState(474);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(468);
					match(SEMI);
					setState(469);
					((VariableDeclarationPartContext)_localctx).variableDeclaration = variableDeclaration();
					_localctx.code += "\n" + ((VariableDeclarationPartContext)_localctx).variableDeclaration.code;
					}
					} 
				}
				setState(476);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			}
			setState(477);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariableDeclarationContext extends ParserRuleContext {
		public String code;
		public IdentifierListContext identifierList;
		public TypeContext type;
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public VariableDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableDeclaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterVariableDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitVariableDeclaration(this);
		}
	}

	public final VariableDeclarationContext variableDeclaration() throws RecognitionException {
		VariableDeclarationContext _localctx = new VariableDeclarationContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_variableDeclaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(479);
			((VariableDeclarationContext)_localctx).identifierList = identifierList();
			setState(480);
			match(COLON);
			setState(481);
			((VariableDeclarationContext)_localctx).type = type();
			((VariableDeclarationContext)_localctx).code =  ((VariableDeclarationContext)_localctx).type.code + " " + ((VariableDeclarationContext)_localctx).identifierList.code + ";";
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcedureAndFunctionDeclarationPartContext extends ParserRuleContext {
		public String code;
		public ProcedureDeclarationContext procedureDeclaration;
		public FunctionDeclarationContext functionDeclaration;
		public ProcedureDeclarationContext procedureDeclaration() {
			return getRuleContext(ProcedureDeclarationContext.class,0);
		}
		public FunctionDeclarationContext functionDeclaration() {
			return getRuleContext(FunctionDeclarationContext.class,0);
		}
		public ProcedureAndFunctionDeclarationPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procedureAndFunctionDeclarationPart; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterProcedureAndFunctionDeclarationPart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitProcedureAndFunctionDeclarationPart(this);
		}
	}

	public final ProcedureAndFunctionDeclarationPartContext procedureAndFunctionDeclarationPart() throws RecognitionException {
		ProcedureAndFunctionDeclarationPartContext _localctx = new ProcedureAndFunctionDeclarationPartContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_procedureAndFunctionDeclarationPart);
		try {
			setState(490);
			switch (_input.LA(1)) {
			case PROCEDURE:
				enterOuterAlt(_localctx, 1);
				{
				setState(484);
				((ProcedureAndFunctionDeclarationPartContext)_localctx).procedureDeclaration = procedureDeclaration();
				((ProcedureAndFunctionDeclarationPartContext)_localctx).code =  ((ProcedureAndFunctionDeclarationPartContext)_localctx).procedureDeclaration.code;
				}
				break;
			case FUNCTION:
				enterOuterAlt(_localctx, 2);
				{
				setState(487);
				((ProcedureAndFunctionDeclarationPartContext)_localctx).functionDeclaration = functionDeclaration();
				((ProcedureAndFunctionDeclarationPartContext)_localctx).code =  ((ProcedureAndFunctionDeclarationPartContext)_localctx).functionDeclaration.code;
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcedureDeclarationContext extends ParserRuleContext {
		public String code;
		public TerminalNode PROCEDURE() { return getToken(PascalParser.PROCEDURE, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(PascalParser.SEMI, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public FormalParameterListContext formalParameterList() {
			return getRuleContext(FormalParameterListContext.class,0);
		}
		public ProcedureDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procedureDeclaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterProcedureDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitProcedureDeclaration(this);
		}
	}

	public final ProcedureDeclarationContext procedureDeclaration() throws RecognitionException {
		ProcedureDeclarationContext _localctx = new ProcedureDeclarationContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_procedureDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(492);
			match(PROCEDURE);
			setState(493);
			identifier();
			setState(495);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(494);
				formalParameterList();
				}
			}

			setState(497);
			match(SEMI);
			setState(498);
			block();

			   
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionDeclarationContext extends ParserRuleContext {
		public String code;
		public TerminalNode FUNCTION() { return getToken(PascalParser.FUNCTION, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public ResultTypeContext resultType() {
			return getRuleContext(ResultTypeContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(PascalParser.SEMI, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public FormalParameterListContext formalParameterList() {
			return getRuleContext(FormalParameterListContext.class,0);
		}
		public FunctionDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDeclaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterFunctionDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitFunctionDeclaration(this);
		}
	}

	public final FunctionDeclarationContext functionDeclaration() throws RecognitionException {
		FunctionDeclarationContext _localctx = new FunctionDeclarationContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_functionDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(501);
			match(FUNCTION);
			setState(502);
			identifier();
			setState(504);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(503);
				formalParameterList();
				}
			}

			setState(506);
			match(COLON);
			setState(507);
			resultType();
			setState(508);
			match(SEMI);
			setState(509);
			block();

			   
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FormalParameterListContext extends ParserRuleContext {
		public String code;
		public FormalParameterSectionContext formalParameterSection;
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public List<FormalParameterSectionContext> formalParameterSection() {
			return getRuleContexts(FormalParameterSectionContext.class);
		}
		public FormalParameterSectionContext formalParameterSection(int i) {
			return getRuleContext(FormalParameterSectionContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public List<TerminalNode> SEMI() { return getTokens(PascalParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(PascalParser.SEMI, i);
		}
		public FormalParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formalParameterList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterFormalParameterList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitFormalParameterList(this);
		}
	}

	public final FormalParameterListContext formalParameterList() throws RecognitionException {
		FormalParameterListContext _localctx = new FormalParameterListContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_formalParameterList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(512);
			match(LPAREN);
			setState(513);
			((FormalParameterListContext)_localctx).formalParameterSection = formalParameterSection();
			((FormalParameterListContext)_localctx).code =  ((FormalParameterListContext)_localctx).formalParameterSection.code;
			setState(521);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SEMI) {
				{
				{
				setState(515);
				match(SEMI);
				setState(516);
				((FormalParameterListContext)_localctx).formalParameterSection = formalParameterSection();
				_localctx.code += ", " + ((FormalParameterListContext)_localctx).formalParameterSection.code;
				}
				}
				setState(523);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(524);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FormalParameterSectionContext extends ParserRuleContext {
		public String code;
		public ParameterGroupContext parameterGroup;
		public ParameterGroupContext parameterGroup() {
			return getRuleContext(ParameterGroupContext.class,0);
		}
		public TerminalNode VAR() { return getToken(PascalParser.VAR, 0); }
		public TerminalNode FUNCTION() { return getToken(PascalParser.FUNCTION, 0); }
		public TerminalNode PROCEDURE() { return getToken(PascalParser.PROCEDURE, 0); }
		public FormalParameterSectionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formalParameterSection; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterFormalParameterSection(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitFormalParameterSection(this);
		}
	}

	public final FormalParameterSectionContext formalParameterSection() throws RecognitionException {
		FormalParameterSectionContext _localctx = new FormalParameterSectionContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_formalParameterSection);
		try {
			setState(535);
			switch (_input.LA(1)) {
			case IDENT:
				enterOuterAlt(_localctx, 1);
				{
				setState(526);
				parameterGroup();
				}
				break;
			case VAR:
				enterOuterAlt(_localctx, 2);
				{
				setState(527);
				match(VAR);
				setState(528);
				((FormalParameterSectionContext)_localctx).parameterGroup = parameterGroup();
				((FormalParameterSectionContext)_localctx).code =  ((FormalParameterSectionContext)_localctx).parameterGroup.code;
				}
				break;
			case FUNCTION:
				enterOuterAlt(_localctx, 3);
				{
				setState(531);
				match(FUNCTION);
				setState(532);
				parameterGroup();
				}
				break;
			case PROCEDURE:
				enterOuterAlt(_localctx, 4);
				{
				setState(533);
				match(PROCEDURE);
				setState(534);
				parameterGroup();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterGroupContext extends ParserRuleContext {
		public String code;
		public IdentifierListContext identifierList;
		public TypeIdentifierContext typeIdentifier;
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public TypeIdentifierContext typeIdentifier() {
			return getRuleContext(TypeIdentifierContext.class,0);
		}
		public ParameterGroupContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterGroup; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterParameterGroup(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitParameterGroup(this);
		}
	}

	public final ParameterGroupContext parameterGroup() throws RecognitionException {
		ParameterGroupContext _localctx = new ParameterGroupContext(_ctx, getState());
		enterRule(_localctx, 92, RULE_parameterGroup);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(537);
			((ParameterGroupContext)_localctx).identifierList = identifierList();
			setState(538);
			match(COLON);
			setState(539);
			((ParameterGroupContext)_localctx).typeIdentifier = typeIdentifier();

			        ((ParameterGroupContext)_localctx).code =  "";
			        for (String id : ((ParameterGroupContext)_localctx).identifierList.ids) {
			            _localctx.code += ((ParameterGroupContext)_localctx).typeIdentifier.code + " " + id + ", ";
			        }
			        if (!_localctx.code.isEmpty()) {
			            ((ParameterGroupContext)_localctx).code =  _localctx.code.substring(0, _localctx.code.length() - 2);
			        }
			   
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdentifierListContext extends ParserRuleContext {
		public String code;
		public List<String> ids =  new ArrayList<String>();
		public IdentifierContext identifier;
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public IdentifierListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifierList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterIdentifierList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitIdentifierList(this);
		}
	}

	public final IdentifierListContext identifierList() throws RecognitionException {
		IdentifierListContext _localctx = new IdentifierListContext(_ctx, getState());
		enterRule(_localctx, 94, RULE_identifierList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(542);
			((IdentifierListContext)_localctx).identifier = identifier();
			((IdentifierListContext)_localctx).code =  (((IdentifierListContext)_localctx).identifier!=null?_input.getText(((IdentifierListContext)_localctx).identifier.start,((IdentifierListContext)_localctx).identifier.stop):null); _localctx.ids.add((((IdentifierListContext)_localctx).identifier!=null?_input.getText(((IdentifierListContext)_localctx).identifier.start,((IdentifierListContext)_localctx).identifier.stop):null));
			setState(550);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(544);
				match(COMMA);
				setState(545);
				((IdentifierListContext)_localctx).identifier = identifier();
				_localctx.code += ", " + (((IdentifierListContext)_localctx).identifier!=null?_input.getText(((IdentifierListContext)_localctx).identifier.start,((IdentifierListContext)_localctx).identifier.stop):null); _localctx.ids.add((((IdentifierListContext)_localctx).identifier!=null?_input.getText(((IdentifierListContext)_localctx).identifier.start,((IdentifierListContext)_localctx).identifier.stop):null));
				}
				}
				setState(552);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstListContext extends ParserRuleContext {
		public List<ConstantContext> constant() {
			return getRuleContexts(ConstantContext.class);
		}
		public ConstantContext constant(int i) {
			return getRuleContext(ConstantContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public ConstListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterConstList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitConstList(this);
		}
	}

	public final ConstListContext constList() throws RecognitionException {
		ConstListContext _localctx = new ConstListContext(_ctx, getState());
		enterRule(_localctx, 96, RULE_constList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(553);
			constant();
			setState(558);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(554);
				match(COMMA);
				setState(555);
				constant();
				}
				}
				setState(560);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ResultTypeContext extends ParserRuleContext {
		public String code;
		public TypeIdentifierContext typeIdentifier;
		public TypeIdentifierContext typeIdentifier() {
			return getRuleContext(TypeIdentifierContext.class,0);
		}
		public ResultTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_resultType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterResultType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitResultType(this);
		}
	}

	public final ResultTypeContext resultType() throws RecognitionException {
		ResultTypeContext _localctx = new ResultTypeContext(_ctx, getState());
		enterRule(_localctx, 98, RULE_resultType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(561);
			((ResultTypeContext)_localctx).typeIdentifier = typeIdentifier();
			((ResultTypeContext)_localctx).code =  ((ResultTypeContext)_localctx).typeIdentifier.code;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public String code;
		public UnlabelledStatementContext unlabelledStatement;
		public LabelContext label() {
			return getRuleContext(LabelContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public UnlabelledStatementContext unlabelledStatement() {
			return getRuleContext(UnlabelledStatementContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitStatement(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 100, RULE_statement);
		try {
			setState(572);
			switch (_input.LA(1)) {
			case NUM_INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(564);
				label();
				setState(565);
				match(COLON);
				setState(566);
				((StatementContext)_localctx).unlabelledStatement = unlabelledStatement();
				((StatementContext)_localctx).code =  ((StatementContext)_localctx).unlabelledStatement.code;
				}
				break;
			case BEGIN:
			case CASE:
			case ELSE:
			case END:
			case FOR:
			case IF:
			case REPEAT:
			case UNTIL:
			case WHILE:
			case WITH:
			case SEMI:
			case AT:
			case IDENT:
				enterOuterAlt(_localctx, 2);
				{
				setState(569);
				((StatementContext)_localctx).unlabelledStatement = unlabelledStatement();
				((StatementContext)_localctx).code =  ((StatementContext)_localctx).unlabelledStatement.code;
				}
				break;
			default:
				throw new NoViableAltException(this);
			}

			    ((StatementContext)_localctx).code =  printWithIndent(_localctx.code);

		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnlabelledStatementContext extends ParserRuleContext {
		public String code;
		public SimpleStatementContext simpleStatement;
		public StructuredStatementContext structuredStatement;
		public SimpleStatementContext simpleStatement() {
			return getRuleContext(SimpleStatementContext.class,0);
		}
		public StructuredStatementContext structuredStatement() {
			return getRuleContext(StructuredStatementContext.class,0);
		}
		public UnlabelledStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unlabelledStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterUnlabelledStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitUnlabelledStatement(this);
		}
	}

	public final UnlabelledStatementContext unlabelledStatement() throws RecognitionException {
		UnlabelledStatementContext _localctx = new UnlabelledStatementContext(_ctx, getState());
		enterRule(_localctx, 102, RULE_unlabelledStatement);
		try {
			setState(580);
			switch (_input.LA(1)) {
			case ELSE:
			case END:
			case UNTIL:
			case SEMI:
			case AT:
			case IDENT:
				enterOuterAlt(_localctx, 1);
				{
				setState(574);
				((UnlabelledStatementContext)_localctx).simpleStatement = simpleStatement();
				((UnlabelledStatementContext)_localctx).code =  ((UnlabelledStatementContext)_localctx).simpleStatement.code;
				}
				break;
			case BEGIN:
			case CASE:
			case FOR:
			case IF:
			case REPEAT:
			case WHILE:
			case WITH:
				enterOuterAlt(_localctx, 2);
				{
				setState(577);
				((UnlabelledStatementContext)_localctx).structuredStatement = structuredStatement();
				((UnlabelledStatementContext)_localctx).code =  ((UnlabelledStatementContext)_localctx).structuredStatement.code;
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SimpleStatementContext extends ParserRuleContext {
		public String code;
		public AssignmentStatementContext assignmentStatement;
		public ProcedureStatementContext procedureStatement;
		public AssignmentStatementContext assignmentStatement() {
			return getRuleContext(AssignmentStatementContext.class,0);
		}
		public ProcedureStatementContext procedureStatement() {
			return getRuleContext(ProcedureStatementContext.class,0);
		}
		public EmptyStatementContext emptyStatement() {
			return getRuleContext(EmptyStatementContext.class,0);
		}
		public SimpleStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterSimpleStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitSimpleStatement(this);
		}
	}

	public final SimpleStatementContext simpleStatement() throws RecognitionException {
		SimpleStatementContext _localctx = new SimpleStatementContext(_ctx, getState());
		enterRule(_localctx, 104, RULE_simpleStatement);
		try {
			setState(591);
			switch ( getInterpreter().adaptivePredict(_input,37,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(582);
				((SimpleStatementContext)_localctx).assignmentStatement = assignmentStatement();
				((SimpleStatementContext)_localctx).code =  ((SimpleStatementContext)_localctx).assignmentStatement.code;
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(585);
				((SimpleStatementContext)_localctx).procedureStatement = procedureStatement();
				((SimpleStatementContext)_localctx).code =  ((SimpleStatementContext)_localctx).procedureStatement.code;
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(588);
				emptyStatement();
				((SimpleStatementContext)_localctx).code =  "";
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignmentStatementContext extends ParserRuleContext {
		public String code;
		public VariableContext variable;
		public ExpressionContext expression;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(PascalParser.ASSIGN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public AssignmentStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignmentStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterAssignmentStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitAssignmentStatement(this);
		}
	}

	public final AssignmentStatementContext assignmentStatement() throws RecognitionException {
		AssignmentStatementContext _localctx = new AssignmentStatementContext(_ctx, getState());
		enterRule(_localctx, 106, RULE_assignmentStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(593);
			((AssignmentStatementContext)_localctx).variable = variable();
			setState(594);
			match(ASSIGN);
			setState(595);
			((AssignmentStatementContext)_localctx).expression = expression();
			((AssignmentStatementContext)_localctx).code =  ((AssignmentStatementContext)_localctx).variable.code + " = " + ((AssignmentStatementContext)_localctx).expression.code;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariableContext extends ParserRuleContext {
		public String code;
		public IdentifierContext identifier;
		public ExpressionContext expression;
		public TerminalNode AT() { return getToken(PascalParser.AT, 0); }
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TerminalNode> LBRACK() { return getTokens(PascalParser.LBRACK); }
		public TerminalNode LBRACK(int i) {
			return getToken(PascalParser.LBRACK, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> RBRACK() { return getTokens(PascalParser.RBRACK); }
		public TerminalNode RBRACK(int i) {
			return getToken(PascalParser.RBRACK, i);
		}
		public List<TerminalNode> LBRACK2() { return getTokens(PascalParser.LBRACK2); }
		public TerminalNode LBRACK2(int i) {
			return getToken(PascalParser.LBRACK2, i);
		}
		public List<TerminalNode> RBRACK2() { return getTokens(PascalParser.RBRACK2); }
		public TerminalNode RBRACK2(int i) {
			return getToken(PascalParser.RBRACK2, i);
		}
		public List<TerminalNode> DOT() { return getTokens(PascalParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(PascalParser.DOT, i);
		}
		public List<TerminalNode> POINTER() { return getTokens(PascalParser.POINTER); }
		public TerminalNode POINTER(int i) {
			return getToken(PascalParser.POINTER, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterVariable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitVariable(this);
		}
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 108, RULE_variable);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(603);
			switch (_input.LA(1)) {
			case AT:
				{
				setState(598);
				match(AT);
				setState(599);
				((VariableContext)_localctx).identifier = identifier();
				}
				break;
			case IDENT:
				{
				setState(600);
				((VariableContext)_localctx).identifier = identifier();
				((VariableContext)_localctx).code =  (((VariableContext)_localctx).identifier!=null?_input.getText(((VariableContext)_localctx).identifier.start,((VariableContext)_localctx).identifier.stop):null);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(635);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LBRACK) | (1L << LBRACK2) | (1L << POINTER) | (1L << DOT))) != 0)) {
				{
				setState(633);
				switch (_input.LA(1)) {
				case LBRACK:
					{
					setState(605);
					match(LBRACK);
					setState(606);
					((VariableContext)_localctx).expression = expression();
					_localctx.code += "[" + ((VariableContext)_localctx).expression.code + "]";
					setState(614);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==COMMA) {
						{
						{
						setState(608);
						match(COMMA);
						setState(609);
						((VariableContext)_localctx).expression = expression();
						_localctx.code += "[" + ((VariableContext)_localctx).expression.code + "]";
						}
						}
						setState(616);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(617);
					match(RBRACK);
					}
					break;
				case LBRACK2:
					{
					setState(619);
					match(LBRACK2);
					setState(620);
					((VariableContext)_localctx).expression = expression();
					setState(625);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==COMMA) {
						{
						{
						setState(621);
						match(COMMA);
						setState(622);
						((VariableContext)_localctx).expression = expression();
						}
						}
						setState(627);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(628);
					match(RBRACK2);
					}
					break;
				case DOT:
					{
					setState(630);
					match(DOT);
					setState(631);
					((VariableContext)_localctx).identifier = identifier();
					}
					break;
				case POINTER:
					{
					setState(632);
					match(POINTER);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(637);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public String code;
		public SimpleExpressionContext simpleExpression;
		public List<SimpleExpressionContext> simpleExpression() {
			return getRuleContexts(SimpleExpressionContext.class);
		}
		public SimpleExpressionContext simpleExpression(int i) {
			return getRuleContext(SimpleExpressionContext.class,i);
		}
		public List<TerminalNode> EQUAL() { return getTokens(PascalParser.EQUAL); }
		public TerminalNode EQUAL(int i) {
			return getToken(PascalParser.EQUAL, i);
		}
		public List<TerminalNode> NOT_EQUAL() { return getTokens(PascalParser.NOT_EQUAL); }
		public TerminalNode NOT_EQUAL(int i) {
			return getToken(PascalParser.NOT_EQUAL, i);
		}
		public List<TerminalNode> LT() { return getTokens(PascalParser.LT); }
		public TerminalNode LT(int i) {
			return getToken(PascalParser.LT, i);
		}
		public List<TerminalNode> LE() { return getTokens(PascalParser.LE); }
		public TerminalNode LE(int i) {
			return getToken(PascalParser.LE, i);
		}
		public List<TerminalNode> GE() { return getTokens(PascalParser.GE); }
		public TerminalNode GE(int i) {
			return getToken(PascalParser.GE, i);
		}
		public List<TerminalNode> GT() { return getTokens(PascalParser.GT); }
		public TerminalNode GT(int i) {
			return getToken(PascalParser.GT, i);
		}
		public List<TerminalNode> IN() { return getTokens(PascalParser.IN); }
		public TerminalNode IN(int i) {
			return getToken(PascalParser.IN, i);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitExpression(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 110, RULE_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(638);
			((ExpressionContext)_localctx).simpleExpression = simpleExpression();
			((ExpressionContext)_localctx).code =  ((ExpressionContext)_localctx).simpleExpression.code;
			setState(661);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IN) | (1L << EQUAL) | (1L << NOT_EQUAL) | (1L << LT) | (1L << LE) | (1L << GE) | (1L << GT))) != 0)) {
				{
				{
				setState(654);
				switch (_input.LA(1)) {
				case EQUAL:
					{
					setState(640);
					match(EQUAL);
					_localctx.code += "==";
					}
					break;
				case NOT_EQUAL:
					{
					setState(642);
					match(NOT_EQUAL);
					_localctx.code += "!=";
					}
					break;
				case LT:
					{
					setState(644);
					match(LT);
					_localctx.code += "<";
					}
					break;
				case LE:
					{
					setState(646);
					match(LE);
					_localctx.code += "<=";
					}
					break;
				case GE:
					{
					setState(648);
					match(GE);
					_localctx.code += ">=";
					}
					break;
				case GT:
					{
					setState(650);
					match(GT);
					_localctx.code += ">";
					}
					break;
				case IN:
					{
					setState(652);
					match(IN);
					_localctx.code += "in";
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(656);
				((ExpressionContext)_localctx).simpleExpression = simpleExpression();
				_localctx.code += ((ExpressionContext)_localctx).simpleExpression.code;
				}
				}
				setState(663);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SimpleExpressionContext extends ParserRuleContext {
		public String code;
		public TermContext term;
		public List<TermContext> term() {
			return getRuleContexts(TermContext.class);
		}
		public TermContext term(int i) {
			return getRuleContext(TermContext.class,i);
		}
		public List<TerminalNode> PLUS() { return getTokens(PascalParser.PLUS); }
		public TerminalNode PLUS(int i) {
			return getToken(PascalParser.PLUS, i);
		}
		public List<TerminalNode> MINUS() { return getTokens(PascalParser.MINUS); }
		public TerminalNode MINUS(int i) {
			return getToken(PascalParser.MINUS, i);
		}
		public List<TerminalNode> OR() { return getTokens(PascalParser.OR); }
		public TerminalNode OR(int i) {
			return getToken(PascalParser.OR, i);
		}
		public SimpleExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterSimpleExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitSimpleExpression(this);
		}
	}

	public final SimpleExpressionContext simpleExpression() throws RecognitionException {
		SimpleExpressionContext _localctx = new SimpleExpressionContext(_ctx, getState());
		enterRule(_localctx, 112, RULE_simpleExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(664);
			((SimpleExpressionContext)_localctx).term = term();
			((SimpleExpressionContext)_localctx).code =  ((SimpleExpressionContext)_localctx).term.code;
			setState(679);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << OR) | (1L << PLUS) | (1L << MINUS))) != 0)) {
				{
				{
				setState(672);
				switch (_input.LA(1)) {
				case PLUS:
					{
					setState(666);
					match(PLUS);
					_localctx.code += " + ";
					}
					break;
				case MINUS:
					{
					setState(668);
					match(MINUS);
					_localctx.code += " - ";
					}
					break;
				case OR:
					{
					setState(670);
					match(OR);
					_localctx.code += " || ";
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(674);
				((SimpleExpressionContext)_localctx).term = term();
				_localctx.code += ((SimpleExpressionContext)_localctx).term.code;
				}
				}
				setState(681);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TermContext extends ParserRuleContext {
		public String code;
		public SignedFactorContext signedFactor;
		public List<SignedFactorContext> signedFactor() {
			return getRuleContexts(SignedFactorContext.class);
		}
		public SignedFactorContext signedFactor(int i) {
			return getRuleContext(SignedFactorContext.class,i);
		}
		public List<TerminalNode> STAR() { return getTokens(PascalParser.STAR); }
		public TerminalNode STAR(int i) {
			return getToken(PascalParser.STAR, i);
		}
		public List<TerminalNode> SLASH() { return getTokens(PascalParser.SLASH); }
		public TerminalNode SLASH(int i) {
			return getToken(PascalParser.SLASH, i);
		}
		public List<TerminalNode> DIV() { return getTokens(PascalParser.DIV); }
		public TerminalNode DIV(int i) {
			return getToken(PascalParser.DIV, i);
		}
		public List<TerminalNode> MOD() { return getTokens(PascalParser.MOD); }
		public TerminalNode MOD(int i) {
			return getToken(PascalParser.MOD, i);
		}
		public List<TerminalNode> AND() { return getTokens(PascalParser.AND); }
		public TerminalNode AND(int i) {
			return getToken(PascalParser.AND, i);
		}
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterTerm(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitTerm(this);
		}
	}

	public final TermContext term() throws RecognitionException {
		TermContext _localctx = new TermContext(_ctx, getState());
		enterRule(_localctx, 114, RULE_term);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(682);
			((TermContext)_localctx).signedFactor = signedFactor();
			((TermContext)_localctx).code =  ((TermContext)_localctx).signedFactor.code;
			setState(701);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << AND) | (1L << DIV) | (1L << MOD) | (1L << STAR) | (1L << SLASH))) != 0)) {
				{
				{
				setState(694);
				switch (_input.LA(1)) {
				case STAR:
					{
					setState(684);
					match(STAR);
					_localctx.code += " * ";
					}
					break;
				case SLASH:
					{
					setState(686);
					match(SLASH);
					_localctx.code += " / ";
					}
					break;
				case DIV:
					{
					setState(688);
					match(DIV);
					_localctx.code += " / ";
					}
					break;
				case MOD:
					{
					setState(690);
					match(MOD);
					_localctx.code += " % ";
					}
					break;
				case AND:
					{
					setState(692);
					match(AND);
					_localctx.code += " && ";
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(696);
				((TermContext)_localctx).signedFactor = signedFactor();
				_localctx.code += ((TermContext)_localctx).signedFactor.code;
				}
				}
				setState(703);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SignedFactorContext extends ParserRuleContext {
		public String code =  "";
		public FactorContext factor;
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public TerminalNode PLUS() { return getToken(PascalParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(PascalParser.MINUS, 0); }
		public SignedFactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_signedFactor; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterSignedFactor(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitSignedFactor(this);
		}
	}

	public final SignedFactorContext signedFactor() throws RecognitionException {
		SignedFactorContext _localctx = new SignedFactorContext(_ctx, getState());
		enterRule(_localctx, 116, RULE_signedFactor);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(708);
			switch (_input.LA(1)) {
			case PLUS:
				{
				setState(704);
				match(PLUS);
				_localctx.code += "+";
				}
				break;
			case MINUS:
				{
				setState(706);
				match(MINUS);
				_localctx.code += "-";
				}
				break;
			case CHR:
			case NIL:
			case NOT:
			case LPAREN:
			case LBRACK:
			case LBRACK2:
			case AT:
			case IDENT:
			case STRING_LITERAL:
			case NUM_INT:
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(710);
			((SignedFactorContext)_localctx).factor = factor();
			_localctx.code += ((SignedFactorContext)_localctx).factor.code;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FactorContext extends ParserRuleContext {
		public String code;
		public VariableContext variable;
		public ExpressionContext expression;
		public FunctionDesignatorContext functionDesignator;
		public UnsignedConstantContext unsignedConstant;
		public FactorContext ft;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public FunctionDesignatorContext functionDesignator() {
			return getRuleContext(FunctionDesignatorContext.class,0);
		}
		public UnsignedConstantContext unsignedConstant() {
			return getRuleContext(UnsignedConstantContext.class,0);
		}
		public SetContext set() {
			return getRuleContext(SetContext.class,0);
		}
		public TerminalNode NOT() { return getToken(PascalParser.NOT, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterFactor(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitFactor(this);
		}
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 118, RULE_factor);
		try {
			setState(732);
			switch ( getInterpreter().adaptivePredict(_input,50,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(713);
				((FactorContext)_localctx).variable = variable();
				((FactorContext)_localctx).code =  ((FactorContext)_localctx).variable.code;
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(716);
				match(LPAREN);
				setState(717);
				((FactorContext)_localctx).expression = expression();
				setState(718);
				match(RPAREN);
				((FactorContext)_localctx).code =  ((FactorContext)_localctx).expression.code;
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(721);
				((FactorContext)_localctx).functionDesignator = functionDesignator();
				((FactorContext)_localctx).code =  ((FactorContext)_localctx).functionDesignator.code;
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(724);
				((FactorContext)_localctx).unsignedConstant = unsignedConstant();
				((FactorContext)_localctx).code =  ((FactorContext)_localctx).unsignedConstant.code;
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(727);
				set();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(728);
				match(NOT);
				setState(729);
				((FactorContext)_localctx).ft = factor();
				((FactorContext)_localctx).code =  "!" + ((FactorContext)_localctx).ft.code; if (((FactorContext)_localctx).ft.code.equals("eof")) { ((FactorContext)_localctx).code =  "1";} 
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnsignedConstantContext extends ParserRuleContext {
		public String code;
		public UnsignedNumberContext unsignedNumber;
		public StringContext string;
		public UnsignedNumberContext unsignedNumber() {
			return getRuleContext(UnsignedNumberContext.class,0);
		}
		public ConstantChrContext constantChr() {
			return getRuleContext(ConstantChrContext.class,0);
		}
		public StringContext string() {
			return getRuleContext(StringContext.class,0);
		}
		public TerminalNode NIL() { return getToken(PascalParser.NIL, 0); }
		public UnsignedConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsignedConstant; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterUnsignedConstant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitUnsignedConstant(this);
		}
	}

	public final UnsignedConstantContext unsignedConstant() throws RecognitionException {
		UnsignedConstantContext _localctx = new UnsignedConstantContext(_ctx, getState());
		enterRule(_localctx, 120, RULE_unsignedConstant);
		try {
			setState(743);
			switch (_input.LA(1)) {
			case NUM_INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(734);
				((UnsignedConstantContext)_localctx).unsignedNumber = unsignedNumber();
				((UnsignedConstantContext)_localctx).code =  (((UnsignedConstantContext)_localctx).unsignedNumber!=null?_input.getText(((UnsignedConstantContext)_localctx).unsignedNumber.start,((UnsignedConstantContext)_localctx).unsignedNumber.stop):null);
				}
				break;
			case CHR:
				enterOuterAlt(_localctx, 2);
				{
				setState(737);
				constantChr();
				}
				break;
			case STRING_LITERAL:
				enterOuterAlt(_localctx, 3);
				{
				setState(738);
				((UnsignedConstantContext)_localctx).string = string();
				((UnsignedConstantContext)_localctx).code =  ((UnsignedConstantContext)_localctx).string.code;
				}
				break;
			case NIL:
				enterOuterAlt(_localctx, 4);
				{
				setState(741);
				match(NIL);
				((UnsignedConstantContext)_localctx).code =  "null";
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionDesignatorContext extends ParserRuleContext {
		public String code;
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public FunctionDesignatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDesignator; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterFunctionDesignator(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitFunctionDesignator(this);
		}
	}

	public final FunctionDesignatorContext functionDesignator() throws RecognitionException {
		FunctionDesignatorContext _localctx = new FunctionDesignatorContext(_ctx, getState());
		enterRule(_localctx, 122, RULE_functionDesignator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(745);
			identifier();
			setState(746);
			match(LPAREN);
			setState(747);
			parameterList();
			setState(748);
			match(RPAREN);
			}

			    ((FunctionDesignatorContext)_localctx).code =  IOWriter.getMapping(_localctx.identifier().getText(), new ArrayList<>(_localctx.parameterList().parameters));

		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterListContext extends ParserRuleContext {
		public List<String> parameters =  new ArrayList<String>();
		public ActualParameterContext actualParameter;
		public List<ActualParameterContext> actualParameter() {
			return getRuleContexts(ActualParameterContext.class);
		}
		public ActualParameterContext actualParameter(int i) {
			return getRuleContext(ActualParameterContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public ParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterParameterList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitParameterList(this);
		}
	}

	public final ParameterListContext parameterList() throws RecognitionException {
		ParameterListContext _localctx = new ParameterListContext(_ctx, getState());
		enterRule(_localctx, 124, RULE_parameterList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(750);
			((ParameterListContext)_localctx).actualParameter = actualParameter();
			_localctx.parameters.add(((ParameterListContext)_localctx).actualParameter.code);
			setState(758);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(752);
				match(COMMA);
				setState(753);
				((ParameterListContext)_localctx).actualParameter = actualParameter();
				_localctx.parameters.add(((ParameterListContext)_localctx).actualParameter.code);
				}
				}
				setState(760);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SetContext extends ParserRuleContext {
		public TerminalNode LBRACK() { return getToken(PascalParser.LBRACK, 0); }
		public ElementListContext elementList() {
			return getRuleContext(ElementListContext.class,0);
		}
		public TerminalNode RBRACK() { return getToken(PascalParser.RBRACK, 0); }
		public TerminalNode LBRACK2() { return getToken(PascalParser.LBRACK2, 0); }
		public TerminalNode RBRACK2() { return getToken(PascalParser.RBRACK2, 0); }
		public SetContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_set; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterSet(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitSet(this);
		}
	}

	public final SetContext set() throws RecognitionException {
		SetContext _localctx = new SetContext(_ctx, getState());
		enterRule(_localctx, 126, RULE_set);
		try {
			setState(769);
			switch (_input.LA(1)) {
			case LBRACK:
				enterOuterAlt(_localctx, 1);
				{
				setState(761);
				match(LBRACK);
				setState(762);
				elementList();
				setState(763);
				match(RBRACK);
				}
				break;
			case LBRACK2:
				enterOuterAlt(_localctx, 2);
				{
				setState(765);
				match(LBRACK2);
				setState(766);
				elementList();
				setState(767);
				match(RBRACK2);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ElementListContext extends ParserRuleContext {
		public List<ElementContext> element() {
			return getRuleContexts(ElementContext.class);
		}
		public ElementContext element(int i) {
			return getRuleContext(ElementContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public ElementListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_elementList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterElementList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitElementList(this);
		}
	}

	public final ElementListContext elementList() throws RecognitionException {
		ElementListContext _localctx = new ElementListContext(_ctx, getState());
		enterRule(_localctx, 128, RULE_elementList);
		int _la;
		try {
			setState(780);
			switch (_input.LA(1)) {
			case CHR:
			case NIL:
			case NOT:
			case PLUS:
			case MINUS:
			case LPAREN:
			case LBRACK:
			case LBRACK2:
			case AT:
			case IDENT:
			case STRING_LITERAL:
			case NUM_INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(771);
				element();
				setState(776);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(772);
					match(COMMA);
					setState(773);
					element();
					}
					}
					setState(778);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			case RBRACK:
			case RBRACK2:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ElementContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode DOTDOT() { return getToken(PascalParser.DOTDOT, 0); }
		public ElementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_element; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterElement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitElement(this);
		}
	}

	public final ElementContext element() throws RecognitionException {
		ElementContext _localctx = new ElementContext(_ctx, getState());
		enterRule(_localctx, 130, RULE_element);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(782);
			expression();
			setState(785);
			_la = _input.LA(1);
			if (_la==DOTDOT) {
				{
				setState(783);
				match(DOTDOT);
				setState(784);
				expression();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcedureStatementContext extends ParserRuleContext {
		public String code;
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public ProcedureStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procedureStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterProcedureStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitProcedureStatement(this);
		}
	}

	public final ProcedureStatementContext procedureStatement() throws RecognitionException {
		ProcedureStatementContext _localctx = new ProcedureStatementContext(_ctx, getState());
		enterRule(_localctx, 132, RULE_procedureStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(787);
			identifier();
			setState(792);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(788);
				match(LPAREN);
				setState(789);
				parameterList();
				setState(790);
				match(RPAREN);
				}
			}

			}

			    ((ProcedureStatementContext)_localctx).code =  IOWriter.getMapping(_localctx.identifier().getText(), _localctx.parameterList() == null ? new ArrayList<>() : new ArrayList<>(_localctx.parameterList().parameters));

		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ActualParameterContext extends ParserRuleContext {
		public String code;
		public ExpressionContext expression;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ActualParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_actualParameter; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterActualParameter(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitActualParameter(this);
		}
	}

	public final ActualParameterContext actualParameter() throws RecognitionException {
		ActualParameterContext _localctx = new ActualParameterContext(_ctx, getState());
		enterRule(_localctx, 134, RULE_actualParameter);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(794);
			((ActualParameterContext)_localctx).expression = expression();
			((ActualParameterContext)_localctx).code =  ((ActualParameterContext)_localctx).expression.code;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class GotoStatementContext extends ParserRuleContext {
		public TerminalNode GOTO() { return getToken(PascalParser.GOTO, 0); }
		public LabelContext label() {
			return getRuleContext(LabelContext.class,0);
		}
		public GotoStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_gotoStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterGotoStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitGotoStatement(this);
		}
	}

	public final GotoStatementContext gotoStatement() throws RecognitionException {
		GotoStatementContext _localctx = new GotoStatementContext(_ctx, getState());
		enterRule(_localctx, 136, RULE_gotoStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(797);
			match(GOTO);
			setState(798);
			label();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class EmptyStatementContext extends ParserRuleContext {
		public EmptyStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_emptyStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterEmptyStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitEmptyStatement(this);
		}
	}

	public final EmptyStatementContext emptyStatement() throws RecognitionException {
		EmptyStatementContext _localctx = new EmptyStatementContext(_ctx, getState());
		enterRule(_localctx, 138, RULE_emptyStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class EmptyContext extends ParserRuleContext {
		public EmptyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_empty; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterEmpty(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitEmpty(this);
		}
	}

	public final EmptyContext empty() throws RecognitionException {
		EmptyContext _localctx = new EmptyContext(_ctx, getState());
		enterRule(_localctx, 140, RULE_empty);
		try {
			enterOuterAlt(_localctx, 1);
			{
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StructuredStatementContext extends ParserRuleContext {
		public String code;
		public CompoundStatementContext compoundStatement;
		public ConditionalStatementContext conditionalStatement;
		public RepetetiveStatementContext repetetiveStatement;
		public CompoundStatementContext compoundStatement() {
			return getRuleContext(CompoundStatementContext.class,0);
		}
		public ConditionalStatementContext conditionalStatement() {
			return getRuleContext(ConditionalStatementContext.class,0);
		}
		public RepetetiveStatementContext repetetiveStatement() {
			return getRuleContext(RepetetiveStatementContext.class,0);
		}
		public WithStatementContext withStatement() {
			return getRuleContext(WithStatementContext.class,0);
		}
		public StructuredStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_structuredStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterStructuredStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitStructuredStatement(this);
		}
	}

	public final StructuredStatementContext structuredStatement() throws RecognitionException {
		StructuredStatementContext _localctx = new StructuredStatementContext(_ctx, getState());
		enterRule(_localctx, 142, RULE_structuredStatement);
		try {
			setState(814);
			switch (_input.LA(1)) {
			case BEGIN:
				enterOuterAlt(_localctx, 1);
				{
				setState(804);
				((StructuredStatementContext)_localctx).compoundStatement = compoundStatement();
				((StructuredStatementContext)_localctx).code =  ((StructuredStatementContext)_localctx).compoundStatement.code;
				}
				break;
			case CASE:
			case IF:
				enterOuterAlt(_localctx, 2);
				{
				setState(807);
				((StructuredStatementContext)_localctx).conditionalStatement = conditionalStatement();
				((StructuredStatementContext)_localctx).code =  ((StructuredStatementContext)_localctx).conditionalStatement.code;
				}
				break;
			case FOR:
			case REPEAT:
			case WHILE:
				enterOuterAlt(_localctx, 3);
				{
				setState(810);
				((StructuredStatementContext)_localctx).repetetiveStatement = repetetiveStatement();
				((StructuredStatementContext)_localctx).code =  ((StructuredStatementContext)_localctx).repetetiveStatement.code;
				}
				break;
			case WITH:
				enterOuterAlt(_localctx, 4);
				{
				setState(813);
				withStatement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CompoundStatementContext extends ParserRuleContext {
		public String code;
		public StatementsContext statements;
		public TerminalNode BEGIN() { return getToken(PascalParser.BEGIN, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode END() { return getToken(PascalParser.END, 0); }
		public CompoundStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compoundStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterCompoundStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitCompoundStatement(this);
		}
	}

	public final CompoundStatementContext compoundStatement() throws RecognitionException {
		CompoundStatementContext _localctx = new CompoundStatementContext(_ctx, getState());
		enterRule(_localctx, 144, RULE_compoundStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(816);
			match(BEGIN);
			setState(817);
			((CompoundStatementContext)_localctx).statements = statements();
			setState(818);
			match(END);
			((CompoundStatementContext)_localctx).code =  ((CompoundStatementContext)_localctx).statements.code;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementsContext extends ParserRuleContext {
		public String code;
		public StatementContext statement;
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public List<TerminalNode> SEMI() { return getTokens(PascalParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(PascalParser.SEMI, i);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterStatements(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitStatements(this);
		}
	}

	public final StatementsContext statements() throws RecognitionException {
		StatementsContext _localctx = new StatementsContext(_ctx, getState());
		enterRule(_localctx, 146, RULE_statements);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(821);
			((StatementsContext)_localctx).statement = statement();
			((StatementsContext)_localctx).code =  ((StatementsContext)_localctx).statement.code.isEmpty() ? "" : ((StatementsContext)_localctx).statement.code + ";";
			setState(829);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SEMI) {
				{
				{
				setState(823);
				match(SEMI);
				setState(824);
				((StatementsContext)_localctx).statement = statement();
				_localctx.code += ((StatementsContext)_localctx).statement.code.isEmpty() ? "" : "\n" + ((StatementsContext)_localctx).statement.code + ";";
				}
				}
				setState(831);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConditionalStatementContext extends ParserRuleContext {
		public String code;
		public IfStatementContext ifStatement;
		public IfStatementContext ifStatement() {
			return getRuleContext(IfStatementContext.class,0);
		}
		public CaseStatementContext caseStatement() {
			return getRuleContext(CaseStatementContext.class,0);
		}
		public ConditionalStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conditionalStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterConditionalStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitConditionalStatement(this);
		}
	}

	public final ConditionalStatementContext conditionalStatement() throws RecognitionException {
		ConditionalStatementContext _localctx = new ConditionalStatementContext(_ctx, getState());
		enterRule(_localctx, 148, RULE_conditionalStatement);
		try {
			setState(836);
			switch (_input.LA(1)) {
			case IF:
				enterOuterAlt(_localctx, 1);
				{
				setState(832);
				((ConditionalStatementContext)_localctx).ifStatement = ifStatement();
				((ConditionalStatementContext)_localctx).code =  ((ConditionalStatementContext)_localctx).ifStatement.code;
				}
				break;
			case CASE:
				enterOuterAlt(_localctx, 2);
				{
				setState(835);
				caseStatement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfStatementContext extends ParserRuleContext {
		public String code;
		public ExpressionContext expression;
		public StatementContext statement;
		public TerminalNode IF() { return getToken(PascalParser.IF, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode THEN() { return getToken(PascalParser.THEN, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(PascalParser.ELSE, 0); }
		public IfStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterIfStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitIfStatement(this);
		}
	}

	public final IfStatementContext ifStatement() throws RecognitionException {
		IfStatementContext _localctx = new IfStatementContext(_ctx, getState());
		enterRule(_localctx, 150, RULE_ifStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(838);
			match(IF);
			setState(839);
			((IfStatementContext)_localctx).expression = expression();
			setState(840);
			match(THEN);
			setState(841);
			((IfStatementContext)_localctx).statement = statement();
			((IfStatementContext)_localctx).code =  "if (" + ((IfStatementContext)_localctx).expression.code + ") {\n" + ((IfStatementContext)_localctx).statement.code + ";" + "\n}"; 
			setState(847);
			switch ( getInterpreter().adaptivePredict(_input,61,_ctx) ) {
			case 1:
				{
				setState(843);
				match(ELSE);
				setState(844);
				((IfStatementContext)_localctx).statement = statement();

				        if (((IfStatementContext)_localctx).statement.code.trim().startsWith("if")) {
				            _localctx.code += " else " + ((IfStatementContext)_localctx).statement.code;
				        } else {
				            _localctx.code += " else {\n" + (((IfStatementContext)_localctx).statement.code.isEmpty() ? "" : ((IfStatementContext)_localctx).statement.code + ";") + "\n}";
				        }
				    
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CaseStatementContext extends ParserRuleContext {
		public TerminalNode CASE() { return getToken(PascalParser.CASE, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode OF() { return getToken(PascalParser.OF, 0); }
		public List<CaseListElementContext> caseListElement() {
			return getRuleContexts(CaseListElementContext.class);
		}
		public CaseListElementContext caseListElement(int i) {
			return getRuleContext(CaseListElementContext.class,i);
		}
		public TerminalNode END() { return getToken(PascalParser.END, 0); }
		public List<TerminalNode> SEMI() { return getTokens(PascalParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(PascalParser.SEMI, i);
		}
		public TerminalNode ELSE() { return getToken(PascalParser.ELSE, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public CaseStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_caseStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterCaseStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitCaseStatement(this);
		}
	}

	public final CaseStatementContext caseStatement() throws RecognitionException {
		CaseStatementContext _localctx = new CaseStatementContext(_ctx, getState());
		enterRule(_localctx, 152, RULE_caseStatement);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(849);
			match(CASE);
			setState(850);
			expression();
			setState(851);
			match(OF);
			setState(852);
			caseListElement();
			setState(857);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,62,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(853);
					match(SEMI);
					setState(854);
					caseListElement();
					}
					} 
				}
				setState(859);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,62,_ctx);
			}
			setState(863);
			_la = _input.LA(1);
			if (_la==SEMI) {
				{
				setState(860);
				match(SEMI);
				setState(861);
				match(ELSE);
				setState(862);
				statements();
				}
			}

			setState(865);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CaseListElementContext extends ParserRuleContext {
		public ConstListContext constList() {
			return getRuleContext(ConstListContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public CaseListElementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_caseListElement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterCaseListElement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitCaseListElement(this);
		}
	}

	public final CaseListElementContext caseListElement() throws RecognitionException {
		CaseListElementContext _localctx = new CaseListElementContext(_ctx, getState());
		enterRule(_localctx, 154, RULE_caseListElement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(867);
			constList();
			setState(868);
			match(COLON);
			setState(869);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RepetetiveStatementContext extends ParserRuleContext {
		public String code;
		public WhileStatementContext whileStatement;
		public RepeatStatementContext repeatStatement;
		public ForStatementContext forStatement;
		public WhileStatementContext whileStatement() {
			return getRuleContext(WhileStatementContext.class,0);
		}
		public RepeatStatementContext repeatStatement() {
			return getRuleContext(RepeatStatementContext.class,0);
		}
		public ForStatementContext forStatement() {
			return getRuleContext(ForStatementContext.class,0);
		}
		public RepetetiveStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_repetetiveStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterRepetetiveStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitRepetetiveStatement(this);
		}
	}

	public final RepetetiveStatementContext repetetiveStatement() throws RecognitionException {
		RepetetiveStatementContext _localctx = new RepetetiveStatementContext(_ctx, getState());
		enterRule(_localctx, 156, RULE_repetetiveStatement);
		try {
			setState(880);
			switch (_input.LA(1)) {
			case WHILE:
				enterOuterAlt(_localctx, 1);
				{
				setState(871);
				((RepetetiveStatementContext)_localctx).whileStatement = whileStatement();
				((RepetetiveStatementContext)_localctx).code =  ((RepetetiveStatementContext)_localctx).whileStatement.code;
				}
				break;
			case REPEAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(874);
				((RepetetiveStatementContext)_localctx).repeatStatement = repeatStatement();
				((RepetetiveStatementContext)_localctx).code =  ((RepetetiveStatementContext)_localctx).repeatStatement.code;
				}
				break;
			case FOR:
				enterOuterAlt(_localctx, 3);
				{
				setState(877);
				((RepetetiveStatementContext)_localctx).forStatement = forStatement();
				((RepetetiveStatementContext)_localctx).code =  ((RepetetiveStatementContext)_localctx).forStatement.code;
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhileStatementContext extends ParserRuleContext {
		public String code;
		public ExpressionContext expression;
		public StatementContext statement;
		public TerminalNode WHILE() { return getToken(PascalParser.WHILE, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode DO() { return getToken(PascalParser.DO, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public WhileStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterWhileStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitWhileStatement(this);
		}
	}

	public final WhileStatementContext whileStatement() throws RecognitionException {
		WhileStatementContext _localctx = new WhileStatementContext(_ctx, getState());
		enterRule(_localctx, 158, RULE_whileStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(882);
			match(WHILE);
			setState(883);
			((WhileStatementContext)_localctx).expression = expression();
			setState(884);
			match(DO);
			setState(885);
			((WhileStatementContext)_localctx).statement = statement();
			((WhileStatementContext)_localctx).code =  "while (" + ((WhileStatementContext)_localctx).expression.code + ") {\n" + ((WhileStatementContext)_localctx).statement.code + "\n}";
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RepeatStatementContext extends ParserRuleContext {
		public String code;
		public StatementsContext statements;
		public ExpressionContext expression;
		public TerminalNode REPEAT() { return getToken(PascalParser.REPEAT, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode UNTIL() { return getToken(PascalParser.UNTIL, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public RepeatStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_repeatStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterRepeatStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitRepeatStatement(this);
		}
	}

	public final RepeatStatementContext repeatStatement() throws RecognitionException {
		RepeatStatementContext _localctx = new RepeatStatementContext(_ctx, getState());
		enterRule(_localctx, 160, RULE_repeatStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(888);
			match(REPEAT);
			setState(889);
			((RepeatStatementContext)_localctx).statements = statements();
			setState(890);
			match(UNTIL);
			setState(891);
			((RepeatStatementContext)_localctx).expression = expression();
			((RepeatStatementContext)_localctx).code =  "do {\n" + ((RepeatStatementContext)_localctx).statements.code + "\n} while (!(" + ((RepeatStatementContext)_localctx).expression.code + "));";
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ForStatementContext extends ParserRuleContext {
		public String code;
		public IdentifierContext identifier;
		public ExpressionContext initialValue;
		public ExpressionContext finalValue;
		public StatementContext statement;
		public TerminalNode FOR() { return getToken(PascalParser.FOR, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(PascalParser.ASSIGN, 0); }
		public TerminalNode DO() { return getToken(PascalParser.DO, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode TO() { return getToken(PascalParser.TO, 0); }
		public TerminalNode DOWNTO() { return getToken(PascalParser.DOWNTO, 0); }
		public ForStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterForStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitForStatement(this);
		}
	}

	public final ForStatementContext forStatement() throws RecognitionException {
		ForStatementContext _localctx = new ForStatementContext(_ctx, getState());
		enterRule(_localctx, 162, RULE_forStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(894);
			match(FOR);
			setState(895);
			((ForStatementContext)_localctx).identifier = identifier();
			setState(896);
			match(ASSIGN);
			{
			setState(897);
			((ForStatementContext)_localctx).initialValue = expression();
			setState(898);
			_la = _input.LA(1);
			if ( !(_la==DOWNTO || _la==TO) ) {
			_errHandler.recoverInline(this);
			} else {
				consume();
			}
			setState(899);
			((ForStatementContext)_localctx).finalValue = expression();
			}
			setState(901);
			match(DO);
			addLeft();
			setState(903);
			((ForStatementContext)_localctx).statement = statement();
			updateIndent();
			((ForStatementContext)_localctx).code =  "for (" + (((ForStatementContext)_localctx).identifier!=null?_input.getText(((ForStatementContext)_localctx).identifier.start,((ForStatementContext)_localctx).identifier.stop):null) + " = " + ((ForStatementContext)_localctx).initialValue.code + "; " + (((ForStatementContext)_localctx).identifier!=null?_input.getText(((ForStatementContext)_localctx).identifier.start,((ForStatementContext)_localctx).identifier.stop):null) + " != " + ((ForStatementContext)_localctx).finalValue.code + (_localctx.TO() != null ? "+1" : "-1") + "; " + (((ForStatementContext)_localctx).identifier!=null?_input.getText(((ForStatementContext)_localctx).identifier.start,((ForStatementContext)_localctx).identifier.stop):null) + (_localctx.TO() != null ? "++" : "--") + ") {\n" + ((ForStatementContext)_localctx).statement.code + ((((ForStatementContext)_localctx).statement.code.endsWith(";") || ((ForStatementContext)_localctx).statement.code.isEmpty()) ? "" : ";") + "\n}";
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WithStatementContext extends ParserRuleContext {
		public TerminalNode WITH() { return getToken(PascalParser.WITH, 0); }
		public RecordVariableListContext recordVariableList() {
			return getRuleContext(RecordVariableListContext.class,0);
		}
		public TerminalNode DO() { return getToken(PascalParser.DO, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public WithStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_withStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterWithStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitWithStatement(this);
		}
	}

	public final WithStatementContext withStatement() throws RecognitionException {
		WithStatementContext _localctx = new WithStatementContext(_ctx, getState());
		enterRule(_localctx, 164, RULE_withStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(907);
			match(WITH);
			setState(908);
			recordVariableList();
			setState(909);
			match(DO);
			setState(910);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RecordVariableListContext extends ParserRuleContext {
		public List<VariableContext> variable() {
			return getRuleContexts(VariableContext.class);
		}
		public VariableContext variable(int i) {
			return getRuleContext(VariableContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public RecordVariableListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recordVariableList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).enterRecordVariableList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PascalListener ) ((PascalListener)listener).exitRecordVariableList(this);
		}
	}

	public final RecordVariableListContext recordVariableList() throws RecognitionException {
		RecordVariableListContext _localctx = new RecordVariableListContext(_ctx, getState());
		enterRule(_localctx, 166, RULE_recordVariableList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(912);
			variable();
			setState(917);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(913);
				match(COMMA);
				setState(914);
				variable();
				}
				}
				setState(919);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3O\u039b\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\4E\tE\4F\tF\4G\tG\4H\tH\4I"+
		"\tI\4J\tJ\4K\tK\4L\tL\4M\tM\4N\tN\4O\tO\4P\tP\4Q\tQ\4R\tR\4S\tS\4T\tT"+
		"\4U\tU\3\2\3\2\5\2\u00ad\n\2\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\5"+
		"\3\u00b9\n\3\3\3\3\3\3\3\3\3\3\3\3\3\5\3\u00c1\n\3\3\4\3\4\3\5\3\5\3\5"+
		"\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\7\5\u00d1\n\5\f\5\16\5\u00d4\13\5"+
		"\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3\b\3"+
		"\b\7\b\u00e8\n\b\f\b\16\b\u00eb\13\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\n\3"+
		"\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\3\13\5\13\u010b\n\13\3\f\3\f\5\f\u010f"+
		"\n\f\3\r\3\r\3\16\3\16\3\17\3\17\3\20\3\20\3\20\3\21\3\21\3\21\3\21\7"+
		"\21\u011e\n\21\f\21\16\21\u0121\13\21\3\21\3\21\3\22\3\22\3\22\3\22\3"+
		"\22\3\22\3\22\5\22\u012c\n\22\3\23\3\23\5\23\u0130\n\23\3\23\3\23\3\23"+
		"\3\24\3\24\5\24\u0137\n\24\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25"+
		"\5\25\u0142\n\25\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\5\26"+
		"\u014e\n\26\3\27\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\30\3\31\3\31\3\31"+
		"\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\5\31\u0166\n\31\5\31"+
		"\u0168\n\31\3\32\3\32\3\32\3\32\3\32\5\32\u016f\n\32\3\33\3\33\3\33\3"+
		"\33\3\33\3\33\5\33\u0177\n\33\3\34\3\34\3\34\3\34\5\34\u017d\n\34\3\34"+
		"\3\34\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\35\7\35\u0189\n\35\f\35\16"+
		"\35\u018c\13\35\3\35\3\35\3\35\3\35\3\35\3\36\3\36\3\36\3\36\3\37\3\37"+
		"\3\37\3\37\5\37\u019b\n\37\3\37\5\37\u019e\n\37\3 \3 \3 \7 \u01a3\n \f"+
		" \16 \u01a6\13 \3!\3!\3!\3!\3\"\3\"\3\"\3\"\3\"\3\"\3\"\7\"\u01b3\n\""+
		"\f\"\16\"\u01b6\13\"\3#\3#\3#\3#\3#\5#\u01bd\n#\3$\3$\3$\3$\3$\3$\3%\3"+
		"%\3%\3%\3&\3&\3\'\3\'\3\'\3\'\5\'\u01cf\n\'\3(\3(\3(\3)\3)\3)\3)\3)\3"+
		")\3)\7)\u01db\n)\f)\16)\u01de\13)\3)\3)\3*\3*\3*\3*\3*\3+\3+\3+\3+\3+"+
		"\3+\5+\u01ed\n+\3,\3,\3,\5,\u01f2\n,\3,\3,\3,\3,\3-\3-\3-\5-\u01fb\n-"+
		"\3-\3-\3-\3-\3-\3-\3.\3.\3.\3.\3.\3.\3.\7.\u020a\n.\f.\16.\u020d\13.\3"+
		".\3.\3/\3/\3/\3/\3/\3/\3/\3/\3/\5/\u021a\n/\3\60\3\60\3\60\3\60\3\60\3"+
		"\61\3\61\3\61\3\61\3\61\3\61\7\61\u0227\n\61\f\61\16\61\u022a\13\61\3"+
		"\62\3\62\3\62\7\62\u022f\n\62\f\62\16\62\u0232\13\62\3\63\3\63\3\63\3"+
		"\64\3\64\3\64\3\64\3\64\3\64\3\64\3\64\5\64\u023f\n\64\3\65\3\65\3\65"+
		"\3\65\3\65\3\65\5\65\u0247\n\65\3\66\3\66\3\66\3\66\3\66\3\66\3\66\3\66"+
		"\3\66\5\66\u0252\n\66\3\67\3\67\3\67\3\67\3\67\38\38\38\38\38\58\u025e"+
		"\n8\38\38\38\38\38\38\38\78\u0267\n8\f8\168\u026a\138\38\38\38\38\38\3"+
		"8\78\u0272\n8\f8\168\u0275\138\38\38\38\38\38\78\u027c\n8\f8\168\u027f"+
		"\138\39\39\39\39\39\39\39\39\39\39\39\39\39\39\39\39\59\u0291\n9\39\3"+
		"9\39\79\u0296\n9\f9\169\u0299\139\3:\3:\3:\3:\3:\3:\3:\3:\5:\u02a3\n:"+
		"\3:\3:\3:\7:\u02a8\n:\f:\16:\u02ab\13:\3;\3;\3;\3;\3;\3;\3;\3;\3;\3;\3"+
		";\3;\5;\u02b9\n;\3;\3;\3;\7;\u02be\n;\f;\16;\u02c1\13;\3<\3<\3<\3<\5<"+
		"\u02c7\n<\3<\3<\3<\3=\3=\3=\3=\3=\3=\3=\3=\3=\3=\3=\3=\3=\3=\3=\3=\3="+
		"\3=\3=\5=\u02df\n=\3>\3>\3>\3>\3>\3>\3>\3>\3>\5>\u02ea\n>\3?\3?\3?\3?"+
		"\3?\3@\3@\3@\3@\3@\3@\7@\u02f7\n@\f@\16@\u02fa\13@\3A\3A\3A\3A\3A\3A\3"+
		"A\3A\5A\u0304\nA\3B\3B\3B\7B\u0309\nB\fB\16B\u030c\13B\3B\5B\u030f\nB"+
		"\3C\3C\3C\5C\u0314\nC\3D\3D\3D\3D\3D\5D\u031b\nD\3E\3E\3E\3F\3F\3F\3G"+
		"\3G\3H\3H\3I\3I\3I\3I\3I\3I\3I\3I\3I\3I\5I\u0331\nI\3J\3J\3J\3J\3J\3K"+
		"\3K\3K\3K\3K\3K\7K\u033e\nK\fK\16K\u0341\13K\3L\3L\3L\3L\5L\u0347\nL\3"+
		"M\3M\3M\3M\3M\3M\3M\3M\3M\5M\u0352\nM\3N\3N\3N\3N\3N\3N\7N\u035a\nN\f"+
		"N\16N\u035d\13N\3N\3N\3N\5N\u0362\nN\3N\3N\3O\3O\3O\3O\3P\3P\3P\3P\3P"+
		"\3P\3P\3P\3P\5P\u0373\nP\3Q\3Q\3Q\3Q\3Q\3Q\3R\3R\3R\3R\3R\3R\3S\3S\3S"+
		"\3S\3S\3S\3S\3S\3S\3S\3S\3S\3S\3T\3T\3T\3T\3T\3U\3U\3U\7U\u0396\nU\fU"+
		"\16U\u0399\13U\3U\2\2V\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"$&(*,"+
		".\60\62\64\668:<>@BDFHJLNPRTVXZ\\^`bdfhjlnprtvxz|~\u0080\u0082\u0084\u0086"+
		"\u0088\u008a\u008c\u008e\u0090\u0092\u0094\u0096\u0098\u009a\u009c\u009e"+
		"\u00a0\u00a2\u00a4\u00a6\u00a8\2\4\3\2+,\4\2\r\r%%\u03b2\2\u00aa\3\2\2"+
		"\2\4\u00c0\3\2\2\2\6\u00c2\3\2\2\2\b\u00d2\3\2\2\2\n\u00da\3\2\2\2\f\u00de"+
		"\3\2\2\2\16\u00e0\3\2\2\2\20\u00ee\3\2\2\2\22\u00f3\3\2\2\2\24\u010a\3"+
		"\2\2\2\26\u010e\3\2\2\2\30\u0110\3\2\2\2\32\u0112\3\2\2\2\34\u0114\3\2"+
		"\2\2\36\u0116\3\2\2\2 \u0119\3\2\2\2\"\u0124\3\2\2\2$\u012d\3\2\2\2&\u0134"+
		"\3\2\2\2(\u0141\3\2\2\2*\u014d\3\2\2\2,\u014f\3\2\2\2.\u0153\3\2\2\2\60"+
		"\u0167\3\2\2\2\62\u016e\3\2\2\2\64\u0176\3\2\2\2\66\u0178\3\2\2\28\u0180"+
		"\3\2\2\2:\u0192\3\2\2\2<\u019d\3\2\2\2>\u019f\3\2\2\2@\u01a7\3\2\2\2B"+
		"\u01ab\3\2\2\2D\u01bc\3\2\2\2F\u01be\3\2\2\2H\u01c4\3\2\2\2J\u01c8\3\2"+
		"\2\2L\u01ce\3\2\2\2N\u01d0\3\2\2\2P\u01d3\3\2\2\2R\u01e1\3\2\2\2T\u01ec"+
		"\3\2\2\2V\u01ee\3\2\2\2X\u01f7\3\2\2\2Z\u0202\3\2\2\2\\\u0219\3\2\2\2"+
		"^\u021b\3\2\2\2`\u0220\3\2\2\2b\u022b\3\2\2\2d\u0233\3\2\2\2f\u023e\3"+
		"\2\2\2h\u0246\3\2\2\2j\u0251\3\2\2\2l\u0253\3\2\2\2n\u025d\3\2\2\2p\u0280"+
		"\3\2\2\2r\u029a\3\2\2\2t\u02ac\3\2\2\2v\u02c6\3\2\2\2x\u02de\3\2\2\2z"+
		"\u02e9\3\2\2\2|\u02eb\3\2\2\2~\u02f0\3\2\2\2\u0080\u0303\3\2\2\2\u0082"+
		"\u030e\3\2\2\2\u0084\u0310\3\2\2\2\u0086\u0315\3\2\2\2\u0088\u031c\3\2"+
		"\2\2\u008a\u031f\3\2\2\2\u008c\u0322\3\2\2\2\u008e\u0324\3\2\2\2\u0090"+
		"\u0330\3\2\2\2\u0092\u0332\3\2\2\2\u0094\u0337\3\2\2\2\u0096\u0346\3\2"+
		"\2\2\u0098\u0348\3\2\2\2\u009a\u0353\3\2\2\2\u009c\u0365\3\2\2\2\u009e"+
		"\u0372\3\2\2\2\u00a0\u0374\3\2\2\2\u00a2\u037a\3\2\2\2\u00a4\u0380\3\2"+
		"\2\2\u00a6\u038d\3\2\2\2\u00a8\u0392\3\2\2\2\u00aa\u00ac\5\4\3\2\u00ab"+
		"\u00ad\7F\2\2\u00ac\u00ab\3\2\2\2\u00ac\u00ad\3\2\2\2\u00ad\u00ae\3\2"+
		"\2\2\u00ae\u00af\5\b\5\2\u00af\u00b0\7A\2\2\u00b0\u00b1\b\2\1\2\u00b1"+
		"\3\3\2\2\2\u00b2\u00b3\7\37\2\2\u00b3\u00b8\5\6\4\2\u00b4\u00b5\79\2\2"+
		"\u00b5\u00b6\5`\61\2\u00b6\u00b7\7:\2\2\u00b7\u00b9\3\2\2\2\u00b8\u00b4"+
		"\3\2\2\2\u00b8\u00b9\3\2\2\2\u00b9\u00ba\3\2\2\2\u00ba\u00bb\7\61\2\2"+
		"\u00bb\u00c1\3\2\2\2\u00bc\u00bd\7E\2\2\u00bd\u00be\5\6\4\2\u00be\u00bf"+
		"\7\61\2\2\u00bf\u00c1\3\2\2\2\u00c0\u00b2\3\2\2\2\u00c0\u00bc\3\2\2\2"+
		"\u00c1\5\3\2\2\2\u00c2\u00c3\7M\2\2\u00c3\7\3\2\2\2\u00c4\u00c5\5\16\b"+
		"\2\u00c5\u00c6\b\5\1\2\u00c6\u00d1\3\2\2\2\u00c7\u00d1\5 \21\2\u00c8\u00c9"+
		"\5P)\2\u00c9\u00ca\b\5\1\2\u00ca\u00d1\3\2\2\2\u00cb\u00cc\5T+\2\u00cc"+
		"\u00cd\b\5\1\2\u00cd\u00d1\3\2\2\2\u00ce\u00d1\5\n\6\2\u00cf\u00d1\7I"+
		"\2\2\u00d0\u00c4\3\2\2\2\u00d0\u00c7\3\2\2\2\u00d0\u00c8\3\2\2\2\u00d0"+
		"\u00cb\3\2\2\2\u00d0\u00ce\3\2\2\2\u00d0\u00cf\3\2\2\2\u00d1\u00d4\3\2"+
		"\2\2\u00d2\u00d0\3\2\2\2\u00d2\u00d3\3\2\2\2\u00d3\u00d5\3\2\2\2\u00d4"+
		"\u00d2\3\2\2\2\u00d5\u00d6\b\5\1\2\u00d6\u00d7\5\u0092J\2\u00d7\u00d8"+
		"\b\5\1\2\u00d8\u00d9\b\5\1\2\u00d9\t\3\2\2\2\u00da\u00db\7G\2\2\u00db"+
		"\u00dc\5`\61\2\u00dc\u00dd\7\61\2\2\u00dd\13\3\2\2\2\u00de\u00df\5\30"+
		"\r\2\u00df\r\3\2\2\2\u00e0\u00e1\7\n\2\2\u00e1\u00e2\5\20\t\2\u00e2\u00e9"+
		"\b\b\1\2\u00e3\u00e4\7\61\2\2\u00e4\u00e5\5\20\t\2\u00e5\u00e6\b\b\1\2"+
		"\u00e6\u00e8\3\2\2\2\u00e7\u00e3\3\2\2\2\u00e8\u00eb\3\2\2\2\u00e9\u00e7"+
		"\3\2\2\2\u00e9\u00ea\3\2\2\2\u00ea\u00ec\3\2\2\2\u00eb\u00e9\3\2\2\2\u00ec"+
		"\u00ed\7\61\2\2\u00ed\17\3\2\2\2\u00ee\u00ef\5\6\4\2\u00ef\u00f0\7\63"+
		"\2\2\u00f0\u00f1\5\24\13\2\u00f1\u00f2\b\t\1\2\u00f2\21\3\2\2\2\u00f3"+
		"\u00f4\7\t\2\2\u00f4\u00f5\79\2\2\u00f5\u00f6\5\30\r\2\u00f6\u00f7\7:"+
		"\2\2\u00f7\23\3\2\2\2\u00f8\u00f9\5\26\f\2\u00f9\u00fa\b\13\1\2\u00fa"+
		"\u010b\3\2\2\2\u00fb\u00fc\5\34\17\2\u00fc\u00fd\5\26\f\2\u00fd\u00fe"+
		"\b\13\1\2\u00fe\u010b\3\2\2\2\u00ff\u0100\5\6\4\2\u0100\u0101\b\13\1\2"+
		"\u0101\u010b\3\2\2\2\u0102\u0103\5\34\17\2\u0103\u0104\5\6\4\2\u0104\u0105"+
		"\b\13\1\2\u0105\u010b\3\2\2\2\u0106\u0107\5\36\20\2\u0107\u0108\b\13\1"+
		"\2\u0108\u010b\3\2\2\2\u0109\u010b\5\22\n\2\u010a\u00f8\3\2\2\2\u010a"+
		"\u00fb\3\2\2\2\u010a\u00ff\3\2\2\2\u010a\u0102\3\2\2\2\u010a\u0106\3\2"+
		"\2\2\u010a\u0109\3\2\2\2\u010b\25\3\2\2\2\u010c\u010f\5\30\r\2\u010d\u010f"+
		"\5\32\16\2\u010e\u010c\3\2\2\2\u010e\u010d\3\2\2\2\u010f\27\3\2\2\2\u0110"+
		"\u0111\7O\2\2\u0111\31\3\2\2\2\u0112\u0113\7O\2\2\u0113\33\3\2\2\2\u0114"+
		"\u0115\t\2\2\2\u0115\35\3\2\2\2\u0116\u0117\7N\2\2\u0117\u0118\b\20\1"+
		"\2\u0118\37\3\2\2\2\u0119\u011a\7&\2\2\u011a\u011f\5\"\22\2\u011b\u011c"+
		"\7\61\2\2\u011c\u011e\5\"\22\2\u011d\u011b\3\2\2\2\u011e\u0121\3\2\2\2"+
		"\u011f\u011d\3\2\2\2\u011f\u0120\3\2\2\2\u0120\u0122\3\2\2\2\u0121\u011f"+
		"\3\2\2\2\u0122\u0123\7\61\2\2\u0123!\3\2\2\2\u0124\u0125\5\6\4\2\u0125"+
		"\u012b\7\63\2\2\u0126\u0127\5(\25\2\u0127\u0128\b\22\1\2\u0128\u012c\3"+
		"\2\2\2\u0129\u012c\5$\23\2\u012a\u012c\5&\24\2\u012b\u0126\3\2\2\2\u012b"+
		"\u0129\3\2\2\2\u012b\u012a\3\2\2\2\u012c#\3\2\2\2\u012d\u012f\7\22\2\2"+
		"\u012e\u0130\5Z.\2\u012f\u012e\3\2\2\2\u012f\u0130\3\2\2\2\u0130\u0131"+
		"\3\2\2\2\u0131\u0132\7\62\2\2\u0132\u0133\5d\63\2\u0133%\3\2\2\2\u0134"+
		"\u0136\7\36\2\2\u0135\u0137\5Z.\2\u0136\u0135\3\2\2\2\u0136\u0137\3\2"+
		"\2\2\u0137\'\3\2\2\2\u0138\u0139\5*\26\2\u0139\u013a\b\25\1\2\u013a\u0142"+
		"\3\2\2\2\u013b\u013c\5\62\32\2\u013c\u013d\b\25\1\2\u013d\u0142\3\2\2"+
		"\2\u013e\u013f\5N(\2\u013f\u0140\b\25\1\2\u0140\u0142\3\2\2\2\u0141\u0138"+
		"\3\2\2\2\u0141\u013b\3\2\2\2\u0141\u013e\3\2\2\2\u0142)\3\2\2\2\u0143"+
		"\u0144\5\60\31\2\u0144\u0145\b\26\1\2\u0145\u014e\3\2\2\2\u0146\u0147"+
		"\5.\30\2\u0147\u0148\b\26\1\2\u0148\u014e\3\2\2\2\u0149\u014e\5,\27\2"+
		"\u014a\u014b\5\66\34\2\u014b\u014c\b\26\1\2\u014c\u014e\3\2\2\2\u014d"+
		"\u0143\3\2\2\2\u014d\u0146\3\2\2\2\u014d\u0149\3\2\2\2\u014d\u014a\3\2"+
		"\2\2\u014e+\3\2\2\2\u014f\u0150\79\2\2\u0150\u0151\5`\61\2\u0151\u0152"+
		"\7:\2\2\u0152-\3\2\2\2\u0153\u0154\5\24\13\2\u0154\u0155\7B\2\2\u0155"+
		"\u0156\5\24\13\2\u0156\u0157\b\30\1\2\u0157/\3\2\2\2\u0158\u0159\5\6\4"+
		"\2\u0159\u015a\b\31\1\2\u015a\u0168\3\2\2\2\u015b\u015c\7\b\2\2\u015c"+
		"\u0166\b\31\1\2\u015d\u015e\7\6\2\2\u015e\u0166\b\31\1\2\u015f\u0160\7"+
		"\26\2\2\u0160\u0166\b\31\1\2\u0161\u0162\7 \2\2\u0162\u0166\b\31\1\2\u0163"+
		"\u0164\7H\2\2\u0164\u0166\b\31\1\2\u0165\u015b\3\2\2\2\u0165\u015d\3\2"+
		"\2\2\u0165\u015f\3\2\2\2\u0165\u0161\3\2\2\2\u0165\u0163\3\2\2\2\u0166"+
		"\u0168\3\2\2\2\u0167\u0158\3\2\2\2\u0167\u0165\3\2\2\2\u0168\61\3\2\2"+
		"\2\u0169\u016a\7\35\2\2\u016a\u016f\5\64\33\2\u016b\u016c\5\64\33\2\u016c"+
		"\u016d\b\32\1\2\u016d\u016f\3\2\2\2\u016e\u0169\3\2\2\2\u016e\u016b\3"+
		"\2\2\2\u016f\63\3\2\2\2\u0170\u0171\58\35\2\u0171\u0172\b\33\1\2\u0172"+
		"\u0177\3\2\2\2\u0173\u0177\5:\36\2\u0174\u0177\5H%\2\u0175\u0177\5L\'"+
		"\2\u0176\u0170\3\2\2\2\u0176\u0173\3\2\2\2\u0176\u0174\3\2\2\2\u0176\u0175"+
		"\3\2\2\2\u0177\65\3\2\2\2\u0178\u0179\7H\2\2\u0179\u017c\7;\2\2\u017a"+
		"\u017d\5\6\4\2\u017b\u017d\5\26\f\2\u017c\u017a\3\2\2\2\u017c\u017b\3"+
		"\2\2\2\u017d\u017e\3\2\2\2\u017e\u017f\7=\2\2\u017f\67\3\2\2\2\u0180\u0181"+
		"\7\4\2\2\u0181\u0182\7;\2\2\u0182\u0183\5*\26\2\u0183\u018a\b\35\1\2\u0184"+
		"\u0185\7\60\2\2\u0185\u0186\5*\26\2\u0186\u0187\b\35\1\2\u0187\u0189\3"+
		"\2\2\2\u0188\u0184\3\2\2\2\u0189\u018c\3\2\2\2\u018a\u0188\3\2\2\2\u018a"+
		"\u018b\3\2\2\2\u018b\u018d\3\2\2\2\u018c\u018a\3\2\2\2\u018d\u018e\7="+
		"\2\2\u018e\u018f\7\33\2\2\u018f\u0190\5(\25\2\u0190\u0191\b\35\1\2\u0191"+
		"9\3\2\2\2\u0192\u0193\7!\2\2\u0193\u0194\5<\37\2\u0194\u0195\7\17\2\2"+
		"\u0195;\3\2\2\2\u0196\u019a\5> \2\u0197\u0198\7\61\2\2\u0198\u019b\5B"+
		"\"\2\u0199\u019b\7\61\2\2\u019a\u0197\3\2\2\2\u019a\u0199\3\2\2\2\u019a"+
		"\u019b\3\2\2\2\u019b\u019e\3\2\2\2\u019c\u019e\5B\"\2\u019d\u0196\3\2"+
		"\2\2\u019d\u019c\3\2\2\2\u019e=\3\2\2\2\u019f\u01a4\5@!\2\u01a0\u01a1"+
		"\7\61\2\2\u01a1\u01a3\5@!\2\u01a2\u01a0\3\2\2\2\u01a3\u01a6\3\2\2\2\u01a4"+
		"\u01a2\3\2\2\2\u01a4\u01a5\3\2\2\2\u01a5?\3\2\2\2\u01a6\u01a4\3\2\2\2"+
		"\u01a7\u01a8\5`\61\2\u01a8\u01a9\7\62\2\2\u01a9\u01aa\5(\25\2\u01aaA\3"+
		"\2\2\2\u01ab\u01ac\7\7\2\2\u01ac\u01ad\5D#\2\u01ad\u01ae\7\33\2\2\u01ae"+
		"\u01b4\5F$\2\u01af\u01b0\7\61\2\2\u01b0\u01b3\5F$\2\u01b1\u01b3\7\61\2"+
		"\2\u01b2\u01af\3\2\2\2\u01b2\u01b1\3\2\2\2\u01b3\u01b6\3\2\2\2\u01b4\u01b2"+
		"\3\2\2\2\u01b4\u01b5\3\2\2\2\u01b5C\3\2\2\2\u01b6\u01b4\3\2\2\2\u01b7"+
		"\u01b8\5\6\4\2\u01b8\u01b9\7\62\2\2\u01b9\u01ba\5\60\31\2\u01ba\u01bd"+
		"\3\2\2\2\u01bb\u01bd\5\60\31\2\u01bc\u01b7\3\2\2\2\u01bc\u01bb\3\2\2\2"+
		"\u01bdE\3\2\2\2\u01be\u01bf\5b\62\2\u01bf\u01c0\7\62\2\2\u01c0\u01c1\7"+
		"9\2\2\u01c1\u01c2\5<\37\2\u01c2\u01c3\7:\2\2\u01c3G\3\2\2\2\u01c4\u01c5"+
		"\7#\2\2\u01c5\u01c6\7\33\2\2\u01c6\u01c7\5J&\2\u01c7I\3\2\2\2\u01c8\u01c9"+
		"\5*\26\2\u01c9K\3\2\2\2\u01ca\u01cb\7\20\2\2\u01cb\u01cc\7\33\2\2\u01cc"+
		"\u01cf\5(\25\2\u01cd\u01cf\7\20\2\2\u01ce\u01ca\3\2\2\2\u01ce\u01cd\3"+
		"\2\2\2\u01cfM\3\2\2\2\u01d0\u01d1\7?\2\2\u01d1\u01d2\5\60\31\2\u01d2O"+
		"\3\2\2\2\u01d3\u01d4\7(\2\2\u01d4\u01d5\5R*\2\u01d5\u01dc\b)\1\2\u01d6"+
		"\u01d7\7\61\2\2\u01d7\u01d8\5R*\2\u01d8\u01d9\b)\1\2\u01d9\u01db\3\2\2"+
		"\2\u01da\u01d6\3\2\2\2\u01db\u01de\3\2\2\2\u01dc\u01da\3\2\2\2\u01dc\u01dd"+
		"\3\2\2\2\u01dd\u01df\3\2\2\2\u01de\u01dc\3\2\2\2\u01df\u01e0\7\61\2\2"+
		"\u01e0Q\3\2\2\2\u01e1\u01e2\5`\61\2\u01e2\u01e3\7\62\2\2\u01e3\u01e4\5"+
		"(\25\2\u01e4\u01e5\b*\1\2\u01e5S\3\2\2\2\u01e6\u01e7\5V,\2\u01e7\u01e8"+
		"\b+\1\2\u01e8\u01ed\3\2\2\2\u01e9\u01ea\5X-\2\u01ea\u01eb\b+\1\2\u01eb"+
		"\u01ed\3\2\2\2\u01ec\u01e6\3\2\2\2\u01ec\u01e9\3\2\2\2\u01edU\3\2\2\2"+
		"\u01ee\u01ef\7\36\2\2\u01ef\u01f1\5\6\4\2\u01f0\u01f2\5Z.\2\u01f1\u01f0"+
		"\3\2\2\2\u01f1\u01f2\3\2\2\2\u01f2\u01f3\3\2\2\2\u01f3\u01f4\7\61\2\2"+
		"\u01f4\u01f5\5\b\5\2\u01f5\u01f6\b,\1\2\u01f6W\3\2\2\2\u01f7\u01f8\7\22"+
		"\2\2\u01f8\u01fa\5\6\4\2\u01f9\u01fb\5Z.\2\u01fa\u01f9\3\2\2\2\u01fa\u01fb"+
		"\3\2\2\2\u01fb\u01fc\3\2\2\2\u01fc\u01fd\7\62\2\2\u01fd\u01fe\5d\63\2"+
		"\u01fe\u01ff\7\61\2\2\u01ff\u0200\5\b\5\2\u0200\u0201\b-\1\2\u0201Y\3"+
		"\2\2\2\u0202\u0203\79\2\2\u0203\u0204\5\\/\2\u0204\u020b\b.\1\2\u0205"+
		"\u0206\7\61\2\2\u0206\u0207\5\\/\2\u0207\u0208\b.\1\2\u0208\u020a\3\2"+
		"\2\2\u0209\u0205\3\2\2\2\u020a\u020d\3\2\2\2\u020b\u0209\3\2\2\2\u020b"+
		"\u020c\3\2\2\2\u020c\u020e\3\2\2\2\u020d\u020b\3\2\2\2\u020e\u020f\7:"+
		"\2\2\u020f[\3\2\2\2\u0210\u021a\5^\60\2\u0211\u0212\7(\2\2\u0212\u0213"+
		"\5^\60\2\u0213\u0214\b/\1\2\u0214\u021a\3\2\2\2\u0215\u0216\7\22\2\2\u0216"+
		"\u021a\5^\60\2\u0217\u0218\7\36\2\2\u0218\u021a\5^\60\2\u0219\u0210\3"+
		"\2\2\2\u0219\u0211\3\2\2\2\u0219\u0215\3\2\2\2\u0219\u0217\3\2\2\2\u021a"+
		"]\3\2\2\2\u021b\u021c\5`\61\2\u021c\u021d\7\62\2\2\u021d\u021e\5\60\31"+
		"\2\u021e\u021f\b\60\1\2\u021f_\3\2\2\2\u0220\u0221\5\6\4\2\u0221\u0228"+
		"\b\61\1\2\u0222\u0223\7\60\2\2\u0223\u0224\5\6\4\2\u0224\u0225\b\61\1"+
		"\2\u0225\u0227\3\2\2\2\u0226\u0222\3\2\2\2\u0227\u022a\3\2\2\2\u0228\u0226"+
		"\3\2\2\2\u0228\u0229\3\2\2\2\u0229a\3\2\2\2\u022a\u0228\3\2\2\2\u022b"+
		"\u0230\5\24\13\2\u022c\u022d\7\60\2\2\u022d\u022f\5\24\13\2\u022e\u022c"+
		"\3\2\2\2\u022f\u0232\3\2\2\2\u0230\u022e\3\2\2\2\u0230\u0231\3\2\2\2\u0231"+
		"c\3\2\2\2\u0232\u0230\3\2\2\2\u0233\u0234\5\60\31\2\u0234\u0235\b\63\1"+
		"\2\u0235e\3\2\2\2\u0236\u0237\5\f\7\2\u0237\u0238\7\62\2\2\u0238\u0239"+
		"\5h\65\2\u0239\u023a\b\64\1\2\u023a\u023f\3\2\2\2\u023b\u023c\5h\65\2"+
		"\u023c\u023d\b\64\1\2\u023d\u023f\3\2\2\2\u023e\u0236\3\2\2\2\u023e\u023b"+
		"\3\2\2\2\u023fg\3\2\2\2\u0240\u0241\5j\66\2\u0241\u0242\b\65\1\2\u0242"+
		"\u0247\3\2\2\2\u0243\u0244\5\u0090I\2\u0244\u0245\b\65\1\2\u0245\u0247"+
		"\3\2\2\2\u0246\u0240\3\2\2\2\u0246\u0243\3\2\2\2\u0247i\3\2\2\2\u0248"+
		"\u0249\5l\67\2\u0249\u024a\b\66\1\2\u024a\u0252\3\2\2\2\u024b\u024c\5"+
		"\u0086D\2\u024c\u024d\b\66\1\2\u024d\u0252\3\2\2\2\u024e\u024f\5\u008c"+
		"G\2\u024f\u0250\b\66\1\2\u0250\u0252\3\2\2\2\u0251\u0248\3\2\2\2\u0251"+
		"\u024b\3\2\2\2\u0251\u024e\3\2\2\2\u0252k\3\2\2\2\u0253\u0254\5n8\2\u0254"+
		"\u0255\7/\2\2\u0255\u0256\5p9\2\u0256\u0257\b\67\1\2\u0257m\3\2\2\2\u0258"+
		"\u0259\7@\2\2\u0259\u025e\5\6\4\2\u025a\u025b\5\6\4\2\u025b\u025c\b8\1"+
		"\2\u025c\u025e\3\2\2\2\u025d\u0258\3\2\2\2\u025d\u025a\3\2\2\2\u025e\u027d"+
		"\3\2\2\2\u025f\u0260\7;\2\2\u0260\u0261\5p9\2\u0261\u0268\b8\1\2\u0262"+
		"\u0263\7\60\2\2\u0263\u0264\5p9\2\u0264\u0265\b8\1\2\u0265\u0267\3\2\2"+
		"\2\u0266\u0262\3\2\2\2\u0267\u026a\3\2\2\2\u0268\u0266\3\2\2\2\u0268\u0269"+
		"\3\2\2\2\u0269\u026b\3\2\2\2\u026a\u0268\3\2\2\2\u026b\u026c\7=\2\2\u026c"+
		"\u027c\3\2\2\2\u026d\u026e\7<\2\2\u026e\u0273\5p9\2\u026f\u0270\7\60\2"+
		"\2\u0270\u0272\5p9\2\u0271\u026f\3\2\2\2\u0272\u0275\3\2\2\2\u0273\u0271"+
		"\3\2\2\2\u0273\u0274\3\2\2\2\u0274\u0276\3\2\2\2\u0275\u0273\3\2\2\2\u0276"+
		"\u0277\7>\2\2\u0277\u027c\3\2\2\2\u0278\u0279\7A\2\2\u0279\u027c\5\6\4"+
		"\2\u027a\u027c\7?\2\2\u027b\u025f\3\2\2\2\u027b\u026d\3\2\2\2\u027b\u0278"+
		"\3\2\2\2\u027b\u027a\3\2\2\2\u027c\u027f\3\2\2\2\u027d\u027b\3\2\2\2\u027d"+
		"\u027e\3\2\2\2\u027eo\3\2\2\2\u027f\u027d\3\2\2\2\u0280\u0281\5r:\2\u0281"+
		"\u0297\b9\1\2\u0282\u0283\7\63\2\2\u0283\u0291\b9\1\2\u0284\u0285\7\64"+
		"\2\2\u0285\u0291\b9\1\2\u0286\u0287\7\65\2\2\u0287\u0291\b9\1\2\u0288"+
		"\u0289\7\66\2\2\u0289\u0291\b9\1\2\u028a\u028b\7\67\2\2\u028b\u0291\b"+
		"9\1\2\u028c\u028d\78\2\2\u028d\u0291\b9\1\2\u028e\u028f\7\25\2\2\u028f"+
		"\u0291\b9\1\2\u0290\u0282\3\2\2\2\u0290\u0284\3\2\2\2\u0290\u0286\3\2"+
		"\2\2\u0290\u0288\3\2\2\2\u0290\u028a\3\2\2\2\u0290\u028c\3\2\2\2\u0290"+
		"\u028e\3\2\2\2\u0291\u0292\3\2\2\2\u0292\u0293\5r:\2\u0293\u0294\b9\1"+
		"\2\u0294\u0296\3\2\2\2\u0295\u0290\3\2\2\2\u0296\u0299\3\2\2\2\u0297\u0295"+
		"\3\2\2\2\u0297\u0298\3\2\2\2\u0298q\3\2\2\2\u0299\u0297\3\2\2\2\u029a"+
		"\u029b\5t;\2\u029b\u02a9\b:\1\2\u029c\u029d\7+\2\2\u029d\u02a3\b:\1\2"+
		"\u029e\u029f\7,\2\2\u029f\u02a3\b:\1\2\u02a0\u02a1\7\34\2\2\u02a1\u02a3"+
		"\b:\1\2\u02a2\u029c\3\2\2\2\u02a2\u029e\3\2\2\2\u02a2\u02a0\3\2\2\2\u02a3"+
		"\u02a4\3\2\2\2\u02a4\u02a5\5t;\2\u02a5\u02a6\b:\1\2\u02a6\u02a8\3\2\2"+
		"\2\u02a7\u02a2\3\2\2\2\u02a8\u02ab\3\2\2\2\u02a9\u02a7\3\2\2\2\u02a9\u02aa"+
		"\3\2\2\2\u02aas\3\2\2\2\u02ab\u02a9\3\2\2\2\u02ac\u02ad\5v<\2\u02ad\u02bf"+
		"\b;\1\2\u02ae\u02af\7-\2\2\u02af\u02b9\b;\1\2\u02b0\u02b1\7.\2\2\u02b1"+
		"\u02b9\b;\1\2\u02b2\u02b3\7\13\2\2\u02b3\u02b9\b;\1\2\u02b4\u02b5\7\30"+
		"\2\2\u02b5\u02b9\b;\1\2\u02b6\u02b7\7\3\2\2\u02b7\u02b9\b;\1\2\u02b8\u02ae"+
		"\3\2\2\2\u02b8\u02b0\3\2\2\2\u02b8\u02b2\3\2\2\2\u02b8\u02b4\3\2\2\2\u02b8"+
		"\u02b6\3\2\2\2\u02b9\u02ba\3\2\2\2\u02ba\u02bb\5v<\2\u02bb\u02bc\b;\1"+
		"\2\u02bc\u02be\3\2\2\2\u02bd\u02b8\3\2\2\2\u02be\u02c1\3\2\2\2\u02bf\u02bd"+
		"\3\2\2\2\u02bf\u02c0\3\2\2\2\u02c0u\3\2\2\2\u02c1\u02bf\3\2\2\2\u02c2"+
		"\u02c3\7+\2\2\u02c3\u02c7\b<\1\2\u02c4\u02c5\7,\2\2\u02c5\u02c7\b<\1\2"+
		"\u02c6\u02c2\3\2\2\2\u02c6\u02c4\3\2\2\2\u02c6\u02c7\3\2\2\2\u02c7\u02c8"+
		"\3\2\2\2\u02c8\u02c9\5x=\2\u02c9\u02ca\b<\1\2\u02caw\3\2\2\2\u02cb\u02cc"+
		"\5n8\2\u02cc\u02cd\b=\1\2\u02cd\u02df\3\2\2\2\u02ce\u02cf\79\2\2\u02cf"+
		"\u02d0\5p9\2\u02d0\u02d1\7:\2\2\u02d1\u02d2\b=\1\2\u02d2\u02df\3\2\2\2"+
		"\u02d3\u02d4\5|?\2\u02d4\u02d5\b=\1\2\u02d5\u02df\3\2\2\2\u02d6\u02d7"+
		"\5z>\2\u02d7\u02d8\b=\1\2\u02d8\u02df\3\2\2\2\u02d9\u02df\5\u0080A\2\u02da"+
		"\u02db\7\32\2\2\u02db\u02dc\5x=\2\u02dc\u02dd\b=\1\2\u02dd\u02df\3\2\2"+
		"\2\u02de\u02cb\3\2\2\2\u02de\u02ce\3\2\2\2\u02de\u02d3\3\2\2\2\u02de\u02d6"+
		"\3\2\2\2\u02de\u02d9\3\2\2\2\u02de\u02da\3\2\2\2\u02dfy\3\2\2\2\u02e0"+
		"\u02e1\5\26\f\2\u02e1\u02e2\b>\1\2\u02e2\u02ea\3\2\2\2\u02e3\u02ea\5\22"+
		"\n\2\u02e4\u02e5\5\36\20\2\u02e5\u02e6\b>\1\2\u02e6\u02ea\3\2\2\2\u02e7"+
		"\u02e8\7\31\2\2\u02e8\u02ea\b>\1\2\u02e9\u02e0\3\2\2\2\u02e9\u02e3\3\2"+
		"\2\2\u02e9\u02e4\3\2\2\2\u02e9\u02e7\3\2\2\2\u02ea{\3\2\2\2\u02eb\u02ec"+
		"\5\6\4\2\u02ec\u02ed\79\2\2\u02ed\u02ee\5~@\2\u02ee\u02ef\7:\2\2\u02ef"+
		"}\3\2\2\2\u02f0\u02f1\5\u0088E\2\u02f1\u02f8\b@\1\2\u02f2\u02f3\7\60\2"+
		"\2\u02f3\u02f4\5\u0088E\2\u02f4\u02f5\b@\1\2\u02f5\u02f7\3\2\2\2\u02f6"+
		"\u02f2\3\2\2\2\u02f7\u02fa\3\2\2\2\u02f8\u02f6\3\2\2\2\u02f8\u02f9\3\2"+
		"\2\2\u02f9\177\3\2\2\2\u02fa\u02f8\3\2\2\2\u02fb\u02fc\7;\2\2\u02fc\u02fd"+
		"\5\u0082B\2\u02fd\u02fe\7=\2\2\u02fe\u0304\3\2\2\2\u02ff\u0300\7<\2\2"+
		"\u0300\u0301\5\u0082B\2\u0301\u0302\7>\2\2\u0302\u0304\3\2\2\2\u0303\u02fb"+
		"\3\2\2\2\u0303\u02ff\3\2\2\2\u0304\u0081\3\2\2\2\u0305\u030a\5\u0084C"+
		"\2\u0306\u0307\7\60\2\2\u0307\u0309\5\u0084C\2\u0308\u0306\3\2\2\2\u0309"+
		"\u030c\3\2\2\2\u030a\u0308\3\2\2\2\u030a\u030b\3\2\2\2\u030b\u030f\3\2"+
		"\2\2\u030c\u030a\3\2\2\2\u030d\u030f\3\2\2\2\u030e\u0305\3\2\2\2\u030e"+
		"\u030d\3\2\2\2\u030f\u0083\3\2\2\2\u0310\u0313\5p9\2\u0311\u0312\7B\2"+
		"\2\u0312\u0314\5p9\2\u0313\u0311\3\2\2\2\u0313\u0314\3\2\2\2\u0314\u0085"+
		"\3\2\2\2\u0315\u031a\5\6\4\2\u0316\u0317\79\2\2\u0317\u0318\5~@\2\u0318"+
		"\u0319\7:\2\2\u0319\u031b\3\2\2\2\u031a\u0316\3\2\2\2\u031a\u031b\3\2"+
		"\2\2\u031b\u0087\3\2\2\2\u031c\u031d\5p9\2\u031d\u031e\bE\1\2\u031e\u0089"+
		"\3\2\2\2\u031f\u0320\7\23\2\2\u0320\u0321\5\f\7\2\u0321\u008b\3\2\2\2"+
		"\u0322\u0323\3\2\2\2\u0323\u008d\3\2\2\2\u0324\u0325\3\2\2\2\u0325\u008f"+
		"\3\2\2\2\u0326\u0327\5\u0092J\2\u0327\u0328\bI\1\2\u0328\u0331\3\2\2\2"+
		"\u0329\u032a\5\u0096L\2\u032a\u032b\bI\1\2\u032b\u0331\3\2\2\2\u032c\u032d"+
		"\5\u009eP\2\u032d\u032e\bI\1\2\u032e\u0331\3\2\2\2\u032f\u0331\5\u00a6"+
		"T\2\u0330\u0326\3\2\2\2\u0330\u0329\3\2\2\2\u0330\u032c\3\2\2\2\u0330"+
		"\u032f\3\2\2\2\u0331\u0091\3\2\2\2\u0332\u0333\7\5\2\2\u0333\u0334\5\u0094"+
		"K\2\u0334\u0335\7\17\2\2\u0335\u0336\bJ\1\2\u0336\u0093\3\2\2\2\u0337"+
		"\u0338\5f\64\2\u0338\u033f\bK\1\2\u0339\u033a\7\61\2\2\u033a\u033b\5f"+
		"\64\2\u033b\u033c\bK\1\2\u033c\u033e\3\2\2\2\u033d\u0339\3\2\2\2\u033e"+
		"\u0341\3\2\2\2\u033f\u033d\3\2\2\2\u033f\u0340\3\2\2\2\u0340\u0095\3\2"+
		"\2\2\u0341\u033f\3\2\2\2\u0342\u0343\5\u0098M\2\u0343\u0344\bL\1\2\u0344"+
		"\u0347\3\2\2\2\u0345\u0347\5\u009aN\2\u0346\u0342\3\2\2\2\u0346\u0345"+
		"\3\2\2\2\u0347\u0097\3\2\2\2\u0348\u0349\7\24\2\2\u0349\u034a\5p9\2\u034a"+
		"\u034b\7$\2\2\u034b\u034c\5f\64\2\u034c\u0351\bM\1\2\u034d\u034e\7\16"+
		"\2\2\u034e\u034f\5f\64\2\u034f\u0350\bM\1\2\u0350\u0352\3\2\2\2\u0351"+
		"\u034d\3\2\2\2\u0351\u0352\3\2\2\2\u0352\u0099\3\2\2\2\u0353\u0354\7\7"+
		"\2\2\u0354\u0355\5p9\2\u0355\u0356\7\33\2\2\u0356\u035b\5\u009cO\2\u0357"+
		"\u0358\7\61\2\2\u0358\u035a\5\u009cO\2\u0359\u0357\3\2\2\2\u035a\u035d"+
		"\3\2\2\2\u035b\u0359\3\2\2\2\u035b\u035c\3\2\2\2\u035c\u0361\3\2\2\2\u035d"+
		"\u035b\3\2\2\2\u035e\u035f\7\61\2\2\u035f\u0360\7\16\2\2\u0360\u0362\5"+
		"\u0094K\2\u0361\u035e\3\2\2\2\u0361\u0362\3\2\2\2\u0362\u0363\3\2\2\2"+
		"\u0363\u0364\7\17\2\2\u0364\u009b\3\2\2\2\u0365\u0366\5b\62\2\u0366\u0367"+
		"\7\62\2\2\u0367\u0368\5f\64\2\u0368\u009d\3\2\2\2\u0369\u036a\5\u00a0"+
		"Q\2\u036a\u036b\bP\1\2\u036b\u0373\3\2\2\2\u036c\u036d\5\u00a2R\2\u036d"+
		"\u036e\bP\1\2\u036e\u0373\3\2\2\2\u036f\u0370\5\u00a4S\2\u0370\u0371\b"+
		"P\1\2\u0371\u0373\3\2\2\2\u0372\u0369\3\2\2\2\u0372\u036c\3\2\2\2\u0372"+
		"\u036f\3\2\2\2\u0373\u009f\3\2\2\2\u0374\u0375\7)\2\2\u0375\u0376\5p9"+
		"\2\u0376\u0377\7\f\2\2\u0377\u0378\5f\64\2\u0378\u0379\bQ\1\2\u0379\u00a1"+
		"\3\2\2\2\u037a\u037b\7\"\2\2\u037b\u037c\5\u0094K\2\u037c\u037d\7\'\2"+
		"\2\u037d\u037e\5p9\2\u037e\u037f\bR\1\2\u037f\u00a3\3\2\2\2\u0380\u0381"+
		"\7\21\2\2\u0381\u0382\5\6\4\2\u0382\u0383\7/\2\2\u0383\u0384\5p9\2\u0384"+
		"\u0385\t\3\2\2\u0385\u0386\5p9\2\u0386\u0387\3\2\2\2\u0387\u0388\7\f\2"+
		"\2\u0388\u0389\bS\1\2\u0389\u038a\5f\64\2\u038a\u038b\bS\1\2\u038b\u038c"+
		"\bS\1\2\u038c\u00a5\3\2\2\2\u038d\u038e\7*\2\2\u038e\u038f\5\u00a8U\2"+
		"\u038f\u0390\7\f\2\2\u0390\u0391\5f\64\2\u0391\u00a7\3\2\2\2\u0392\u0397"+
		"\5n8\2\u0393\u0394\7\60\2\2\u0394\u0396\5n8\2\u0395\u0393\3\2\2\2\u0396"+
		"\u0399\3\2\2\2\u0397\u0395\3\2\2\2\u0397\u0398\3\2\2\2\u0398\u00a9\3\2"+
		"\2\2\u0399\u0397\3\2\2\2D\u00ac\u00b8\u00c0\u00d0\u00d2\u00e9\u010a\u010e"+
		"\u011f\u012b\u012f\u0136\u0141\u014d\u0165\u0167\u016e\u0176\u017c\u018a"+
		"\u019a\u019d\u01a4\u01b2\u01b4\u01bc\u01ce\u01dc\u01ec\u01f1\u01fa\u020b"+
		"\u0219\u0228\u0230\u023e\u0246\u0251\u025d\u0268\u0273\u027b\u027d\u0290"+
		"\u0297\u02a2\u02a9\u02b8\u02bf\u02c6\u02de\u02e9\u02f8\u0303\u030a\u030e"+
		"\u0313\u031a\u0330\u033f\u0346\u0351\u035b\u0361\u0372\u0397";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}