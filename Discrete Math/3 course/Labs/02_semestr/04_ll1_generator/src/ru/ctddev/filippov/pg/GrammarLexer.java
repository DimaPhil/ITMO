// Generated from /home/dmitry/Documents/work/git/pg/Grammar.g4 by ANTLR 4.5.1
package ru.ctddev.filippov.pg;

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class GrammarLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.5.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		NEWLINE=10, NON_TERM_NAME=11, TERM_NAME=12, MIX_CASE_NAME=13, JAVACODE=14, 
		LEFT_PAREN=15, RIGHT_PAREN=16, WS=17;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
		"NEWLINE", "NON_TERM_NAME", "TERM_NAME", "MIX_CASE_NAME", "JAVACODE", 
		"LEFT_PAREN", "RIGHT_PAREN", "WS"
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


	public GrammarLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Grammar.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2\23y\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\t\3\t"+
		"\3\n\3\n\3\13\5\13L\n\13\3\13\3\13\3\f\6\fQ\n\f\r\f\16\fR\3\r\6\rV\n\r"+
		"\r\r\16\rW\3\16\6\16[\n\16\r\16\16\16\\\3\17\3\17\6\17a\n\17\r\17\16\17"+
		"b\3\17\5\17f\n\17\7\17h\n\17\f\17\16\17k\13\17\3\17\3\17\3\20\3\20\3\21"+
		"\3\21\3\22\6\22t\n\22\r\22\16\22u\3\22\3\22\2\2\23\3\3\5\4\7\5\t\6\13"+
		"\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23\3\2\7"+
		"\4\2aac|\4\2C\\aa\5\2C\\aac|\4\2}}\177\177\4\2\13\13\"\"\u0080\2\3\3\2"+
		"\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17"+
		"\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2"+
		"\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\3%\3"+
		"\2\2\2\5\'\3\2\2\2\7/\3\2\2\2\t8\3\2\2\2\13:\3\2\2\2\r<\3\2\2\2\17>\3"+
		"\2\2\2\21F\3\2\2\2\23H\3\2\2\2\25K\3\2\2\2\27P\3\2\2\2\31U\3\2\2\2\33"+
		"Z\3\2\2\2\35^\3\2\2\2\37n\3\2\2\2!p\3\2\2\2#s\3\2\2\2%&\7=\2\2&\4\3\2"+
		"\2\2\'(\7B\2\2()\7j\2\2)*\7g\2\2*+\7c\2\2+,\7f\2\2,-\7g\2\2-.\7t\2\2."+
		"\6\3\2\2\2/\60\7B\2\2\60\61\7o\2\2\61\62\7g\2\2\62\63\7o\2\2\63\64\7d"+
		"\2\2\64\65\7g\2\2\65\66\7t\2\2\66\67\7u\2\2\67\b\3\2\2\289\7<\2\29\n\3"+
		"\2\2\2:;\7~\2\2;\f\3\2\2\2<=\7)\2\2=\16\3\2\2\2>?\7t\2\2?@\7g\2\2@A\7"+
		"v\2\2AB\7w\2\2BC\7t\2\2CD\7p\2\2DE\7u\2\2E\20\3\2\2\2FG\7]\2\2G\22\3\2"+
		"\2\2HI\7_\2\2I\24\3\2\2\2JL\7\17\2\2KJ\3\2\2\2KL\3\2\2\2LM\3\2\2\2MN\7"+
		"\f\2\2N\26\3\2\2\2OQ\t\2\2\2PO\3\2\2\2QR\3\2\2\2RP\3\2\2\2RS\3\2\2\2S"+
		"\30\3\2\2\2TV\t\3\2\2UT\3\2\2\2VW\3\2\2\2WU\3\2\2\2WX\3\2\2\2X\32\3\2"+
		"\2\2Y[\t\4\2\2ZY\3\2\2\2[\\\3\2\2\2\\Z\3\2\2\2\\]\3\2\2\2]\34\3\2\2\2"+
		"^i\7}\2\2_a\n\5\2\2`_\3\2\2\2ab\3\2\2\2b`\3\2\2\2bc\3\2\2\2ce\3\2\2\2"+
		"df\5\35\17\2ed\3\2\2\2ef\3\2\2\2fh\3\2\2\2g`\3\2\2\2hk\3\2\2\2ig\3\2\2"+
		"\2ij\3\2\2\2jl\3\2\2\2ki\3\2\2\2lm\7\177\2\2m\36\3\2\2\2no\7*\2\2o \3"+
		"\2\2\2pq\7+\2\2q\"\3\2\2\2rt\t\6\2\2sr\3\2\2\2tu\3\2\2\2us\3\2\2\2uv\3"+
		"\2\2\2vw\3\2\2\2wx\b\22\2\2x$\3\2\2\2\13\2KRW\\beiu\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}