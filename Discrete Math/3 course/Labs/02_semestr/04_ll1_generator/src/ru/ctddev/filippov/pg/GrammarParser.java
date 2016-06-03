// Generated from /home/dmitry/Documents/work/git/pg/Grammar.g4 by ANTLR 4.5.1

package ru.ctddev.filippov.pg;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class GrammarParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.5.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		NEWLINE=10, NON_TERM_NAME=11, TERM_NAME=12, MIX_CASE_NAME=13, JAVACODE=14, 
		LEFT_PAREN=15, RIGHT_PAREN=16, WS=17;
	public static final int
		RULE_main = 0, RULE_header = 1, RULE_members = 2, RULE_curRule = 3, RULE_nonTermProduction = 4, 
		RULE_nodeNonTermProduction = 5, RULE_termProduction = 6, RULE_declRet = 7, 
		RULE_type = 8;
	public static final String[] ruleNames = {
		"main", "header", "members", "curRule", "nonTermProduction", "nodeNonTermProduction", 
		"termProduction", "declRet", "type"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "';'", "'@header'", "'@members'", "':'", "'|'", "'''", "'returns'", 
		"'['", "']'", null, null, null, null, null, "'('", "')'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, null, null, null, null, "NEWLINE", 
		"NON_TERM_NAME", "TERM_NAME", "MIX_CASE_NAME", "JAVACODE", "LEFT_PAREN", 
		"RIGHT_PAREN", "WS"
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
	public String getGrammarFileName() { return "Grammar.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public GrammarParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class MainContext extends ParserRuleContext {
		public HeaderContext header() {
			return getRuleContext(HeaderContext.class,0);
		}
		public MembersContext members() {
			return getRuleContext(MembersContext.class,0);
		}
		public List<TerminalNode> NEWLINE() { return getTokens(GrammarParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(GrammarParser.NEWLINE, i);
		}
		public List<CurRuleContext> curRule() {
			return getRuleContexts(CurRuleContext.class);
		}
		public CurRuleContext curRule(int i) {
			return getRuleContext(CurRuleContext.class,i);
		}
		public MainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterMain(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitMain(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitMain(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MainContext main() throws RecognitionException {
		MainContext _localctx = new MainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_main);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(21);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(18);
				match(NEWLINE);
				}
				}
				setState(23);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(24);
			header();
			setState(28);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(25);
					match(NEWLINE);
					}
					} 
				}
				setState(30);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			}
			}
			{
			setState(34);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(31);
				match(NEWLINE);
				}
				}
				setState(36);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(37);
			members();
			setState(41);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(38);
					match(NEWLINE);
					}
					} 
				}
				setState(43);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			}
			}
			{
			setState(51);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << NEWLINE) | (1L << NON_TERM_NAME) | (1L << TERM_NAME))) != 0)) {
				{
				setState(49);
				switch (_input.LA(1)) {
				case NON_TERM_NAME:
				case TERM_NAME:
					{
					{
					setState(44);
					curRule();
					setState(45);
					match(T__0);
					setState(46);
					match(NEWLINE);
					}
					}
					break;
				case NEWLINE:
					{
					setState(48);
					match(NEWLINE);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(53);
				_errHandler.sync(this);
				_la = _input.LA(1);
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

	public static class HeaderContext extends ParserRuleContext {
		public HeaderContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_header; }
	 
		public HeaderContext() { }
		public void copyFrom(HeaderContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class HeaderLabelContext extends HeaderContext {
		public TerminalNode JAVACODE() { return getToken(GrammarParser.JAVACODE, 0); }
		public TerminalNode NEWLINE() { return getToken(GrammarParser.NEWLINE, 0); }
		public HeaderLabelContext(HeaderContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterHeaderLabel(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitHeaderLabel(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitHeaderLabel(this);
			else return visitor.visitChildren(this);
		}
	}

	public final HeaderContext header() throws RecognitionException {
		HeaderContext _localctx = new HeaderContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_header);
		try {
			_localctx = new HeaderLabelContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(54);
			match(T__1);
			setState(55);
			match(JAVACODE);
			setState(56);
			match(NEWLINE);
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

	public static class MembersContext extends ParserRuleContext {
		public MembersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_members; }
	 
		public MembersContext() { }
		public void copyFrom(MembersContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class MembersLabelContext extends MembersContext {
		public TerminalNode JAVACODE() { return getToken(GrammarParser.JAVACODE, 0); }
		public TerminalNode NEWLINE() { return getToken(GrammarParser.NEWLINE, 0); }
		public MembersLabelContext(MembersContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterMembersLabel(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitMembersLabel(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitMembersLabel(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MembersContext members() throws RecognitionException {
		MembersContext _localctx = new MembersContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_members);
		try {
			_localctx = new MembersLabelContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(58);
			match(T__2);
			setState(59);
			match(JAVACODE);
			setState(60);
			match(NEWLINE);
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

	public static class CurRuleContext extends ParserRuleContext {
		public CurRuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_curRule; }
	 
		public CurRuleContext() { }
		public void copyFrom(CurRuleContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class TermLabelContext extends CurRuleContext {
		public TerminalNode TERM_NAME() { return getToken(GrammarParser.TERM_NAME, 0); }
		public List<TermProductionContext> termProduction() {
			return getRuleContexts(TermProductionContext.class);
		}
		public TermProductionContext termProduction(int i) {
			return getRuleContext(TermProductionContext.class,i);
		}
		public TermLabelContext(CurRuleContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterTermLabel(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitTermLabel(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitTermLabel(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class NonTermLabelContext extends CurRuleContext {
		public TerminalNode NON_TERM_NAME() { return getToken(GrammarParser.NON_TERM_NAME, 0); }
		public List<NonTermProductionContext> nonTermProduction() {
			return getRuleContexts(NonTermProductionContext.class);
		}
		public NonTermProductionContext nonTermProduction(int i) {
			return getRuleContext(NonTermProductionContext.class,i);
		}
		public DeclRetContext declRet() {
			return getRuleContext(DeclRetContext.class,0);
		}
		public NonTermLabelContext(CurRuleContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterNonTermLabel(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitNonTermLabel(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitNonTermLabel(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CurRuleContext curRule() throws RecognitionException {
		CurRuleContext _localctx = new CurRuleContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_curRule);
		int _la;
		try {
			setState(85);
			switch (_input.LA(1)) {
			case NON_TERM_NAME:
				_localctx = new NonTermLabelContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(62);
				match(NON_TERM_NAME);
				setState(64);
				_la = _input.LA(1);
				if (_la==T__6) {
					{
					setState(63);
					declRet();
					}
				}

				setState(66);
				match(T__3);
				setState(67);
				nonTermProduction();
				setState(72);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__4) {
					{
					{
					setState(68);
					match(T__4);
					setState(69);
					nonTermProduction();
					}
					}
					setState(74);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			case TERM_NAME:
				_localctx = new TermLabelContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(75);
				match(TERM_NAME);
				setState(76);
				match(T__3);
				setState(77);
				termProduction();
				setState(82);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__4) {
					{
					{
					setState(78);
					match(T__4);
					setState(79);
					termProduction();
					}
					}
					setState(84);
					_errHandler.sync(this);
					_la = _input.LA(1);
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

	public static class NonTermProductionContext extends ParserRuleContext {
		public List<NodeNonTermProductionContext> nodeNonTermProduction() {
			return getRuleContexts(NodeNonTermProductionContext.class);
		}
		public NodeNonTermProductionContext nodeNonTermProduction(int i) {
			return getRuleContext(NodeNonTermProductionContext.class,i);
		}
		public TerminalNode JAVACODE() { return getToken(GrammarParser.JAVACODE, 0); }
		public NonTermProductionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nonTermProduction; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterNonTermProduction(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitNonTermProduction(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitNonTermProduction(this);
			else return visitor.visitChildren(this);
		}
	}

	public final NonTermProductionContext nonTermProduction() throws RecognitionException {
		NonTermProductionContext _localctx = new NonTermProductionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_nonTermProduction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(90);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NON_TERM_NAME || _la==TERM_NAME) {
				{
				{
				setState(87);
				nodeNonTermProduction();
				}
				}
				setState(92);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(94);
			_la = _input.LA(1);
			if (_la==JAVACODE) {
				{
				setState(93);
				match(JAVACODE);
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

	public static class NodeNonTermProductionContext extends ParserRuleContext {
		public TerminalNode NON_TERM_NAME() { return getToken(GrammarParser.NON_TERM_NAME, 0); }
		public TerminalNode TERM_NAME() { return getToken(GrammarParser.TERM_NAME, 0); }
		public NodeNonTermProductionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nodeNonTermProduction; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterNodeNonTermProduction(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitNodeNonTermProduction(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitNodeNonTermProduction(this);
			else return visitor.visitChildren(this);
		}
	}

	public final NodeNonTermProductionContext nodeNonTermProduction() throws RecognitionException {
		NodeNonTermProductionContext _localctx = new NodeNonTermProductionContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_nodeNonTermProduction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(96);
			_la = _input.LA(1);
			if ( !(_la==NON_TERM_NAME || _la==TERM_NAME) ) {
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

	public static class TermProductionContext extends ParserRuleContext {
		public List<TerminalNode> NON_TERM_NAME() { return getTokens(GrammarParser.NON_TERM_NAME); }
		public TerminalNode NON_TERM_NAME(int i) {
			return getToken(GrammarParser.NON_TERM_NAME, i);
		}
		public List<TerminalNode> LEFT_PAREN() { return getTokens(GrammarParser.LEFT_PAREN); }
		public TerminalNode LEFT_PAREN(int i) {
			return getToken(GrammarParser.LEFT_PAREN, i);
		}
		public List<TerminalNode> RIGHT_PAREN() { return getTokens(GrammarParser.RIGHT_PAREN); }
		public TerminalNode RIGHT_PAREN(int i) {
			return getToken(GrammarParser.RIGHT_PAREN, i);
		}
		public TermProductionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_termProduction; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterTermProduction(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitTermProduction(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitTermProduction(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TermProductionContext termProduction() throws RecognitionException {
		TermProductionContext _localctx = new TermProductionContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_termProduction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(103);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__5) {
				{
				{
				setState(98);
				match(T__5);
				setState(99);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << NON_TERM_NAME) | (1L << LEFT_PAREN) | (1L << RIGHT_PAREN))) != 0)) ) {
				_errHandler.recoverInline(this);
				} else {
					consume();
				}
				setState(100);
				match(T__5);
				}
				}
				setState(105);
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

	public static class DeclRetContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public DeclRetContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declRet; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterDeclRet(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitDeclRet(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitDeclRet(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DeclRetContext declRet() throws RecognitionException {
		DeclRetContext _localctx = new DeclRetContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_declRet);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(106);
			match(T__6);
			setState(107);
			match(T__7);
			setState(108);
			type();
			setState(109);
			match(T__8);
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
		public TerminalNode NON_TERM_NAME() { return getToken(GrammarParser.NON_TERM_NAME, 0); }
		public TerminalNode TERM_NAME() { return getToken(GrammarParser.TERM_NAME, 0); }
		public TerminalNode MIX_CASE_NAME() { return getToken(GrammarParser.MIX_CASE_NAME, 0); }
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitType(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(111);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << NON_TERM_NAME) | (1L << TERM_NAME) | (1L << MIX_CASE_NAME))) != 0)) ) {
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

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3\23t\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\3\2\7\2\26"+
		"\n\2\f\2\16\2\31\13\2\3\2\3\2\7\2\35\n\2\f\2\16\2 \13\2\3\2\7\2#\n\2\f"+
		"\2\16\2&\13\2\3\2\3\2\7\2*\n\2\f\2\16\2-\13\2\3\2\3\2\3\2\3\2\3\2\7\2"+
		"\64\n\2\f\2\16\2\67\13\2\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\5\3\5\5\5C"+
		"\n\5\3\5\3\5\3\5\3\5\7\5I\n\5\f\5\16\5L\13\5\3\5\3\5\3\5\3\5\3\5\7\5S"+
		"\n\5\f\5\16\5V\13\5\5\5X\n\5\3\6\7\6[\n\6\f\6\16\6^\13\6\3\6\5\6a\n\6"+
		"\3\7\3\7\3\b\3\b\3\b\7\bh\n\b\f\b\16\bk\13\b\3\t\3\t\3\t\3\t\3\t\3\n\3"+
		"\n\3\n\2\2\13\2\4\6\b\n\f\16\20\22\2\5\3\2\r\16\4\2\r\r\21\22\3\2\r\17"+
		"w\2\27\3\2\2\2\48\3\2\2\2\6<\3\2\2\2\bW\3\2\2\2\n\\\3\2\2\2\fb\3\2\2\2"+
		"\16i\3\2\2\2\20l\3\2\2\2\22q\3\2\2\2\24\26\7\f\2\2\25\24\3\2\2\2\26\31"+
		"\3\2\2\2\27\25\3\2\2\2\27\30\3\2\2\2\30\32\3\2\2\2\31\27\3\2\2\2\32\36"+
		"\5\4\3\2\33\35\7\f\2\2\34\33\3\2\2\2\35 \3\2\2\2\36\34\3\2\2\2\36\37\3"+
		"\2\2\2\37$\3\2\2\2 \36\3\2\2\2!#\7\f\2\2\"!\3\2\2\2#&\3\2\2\2$\"\3\2\2"+
		"\2$%\3\2\2\2%\'\3\2\2\2&$\3\2\2\2\'+\5\6\4\2(*\7\f\2\2)(\3\2\2\2*-\3\2"+
		"\2\2+)\3\2\2\2+,\3\2\2\2,\65\3\2\2\2-+\3\2\2\2./\5\b\5\2/\60\7\3\2\2\60"+
		"\61\7\f\2\2\61\64\3\2\2\2\62\64\7\f\2\2\63.\3\2\2\2\63\62\3\2\2\2\64\67"+
		"\3\2\2\2\65\63\3\2\2\2\65\66\3\2\2\2\66\3\3\2\2\2\67\65\3\2\2\289\7\4"+
		"\2\29:\7\20\2\2:;\7\f\2\2;\5\3\2\2\2<=\7\5\2\2=>\7\20\2\2>?\7\f\2\2?\7"+
		"\3\2\2\2@B\7\r\2\2AC\5\20\t\2BA\3\2\2\2BC\3\2\2\2CD\3\2\2\2DE\7\6\2\2"+
		"EJ\5\n\6\2FG\7\7\2\2GI\5\n\6\2HF\3\2\2\2IL\3\2\2\2JH\3\2\2\2JK\3\2\2\2"+
		"KX\3\2\2\2LJ\3\2\2\2MN\7\16\2\2NO\7\6\2\2OT\5\16\b\2PQ\7\7\2\2QS\5\16"+
		"\b\2RP\3\2\2\2SV\3\2\2\2TR\3\2\2\2TU\3\2\2\2UX\3\2\2\2VT\3\2\2\2W@\3\2"+
		"\2\2WM\3\2\2\2X\t\3\2\2\2Y[\5\f\7\2ZY\3\2\2\2[^\3\2\2\2\\Z\3\2\2\2\\]"+
		"\3\2\2\2]`\3\2\2\2^\\\3\2\2\2_a\7\20\2\2`_\3\2\2\2`a\3\2\2\2a\13\3\2\2"+
		"\2bc\t\2\2\2c\r\3\2\2\2de\7\b\2\2ef\t\3\2\2fh\7\b\2\2gd\3\2\2\2hk\3\2"+
		"\2\2ig\3\2\2\2ij\3\2\2\2j\17\3\2\2\2ki\3\2\2\2lm\7\t\2\2mn\7\n\2\2no\5"+
		"\22\n\2op\7\13\2\2p\21\3\2\2\2qr\t\4\2\2r\23\3\2\2\2\17\27\36$+\63\65"+
		"BJTW\\`i";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}