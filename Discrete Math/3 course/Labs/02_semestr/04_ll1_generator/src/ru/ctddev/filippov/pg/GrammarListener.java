// Generated from /home/dmitry/Documents/work/git/pg/Grammar.g4 by ANTLR 4.5.1

package ru.ctddev.filippov.pg;

import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link GrammarParser}.
 */
public interface GrammarListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link GrammarParser#main}.
	 * @param ctx the parse tree
	 */
	void enterMain(GrammarParser.MainContext ctx);
	/**
	 * Exit a parse tree produced by {@link GrammarParser#main}.
	 * @param ctx the parse tree
	 */
	void exitMain(GrammarParser.MainContext ctx);
	/**
	 * Enter a parse tree produced by the {@code HeaderLabel}
	 * labeled alternative in {@link GrammarParser#header}.
	 * @param ctx the parse tree
	 */
	void enterHeaderLabel(GrammarParser.HeaderLabelContext ctx);
	/**
	 * Exit a parse tree produced by the {@code HeaderLabel}
	 * labeled alternative in {@link GrammarParser#header}.
	 * @param ctx the parse tree
	 */
	void exitHeaderLabel(GrammarParser.HeaderLabelContext ctx);
	/**
	 * Enter a parse tree produced by the {@code MembersLabel}
	 * labeled alternative in {@link GrammarParser#members}.
	 * @param ctx the parse tree
	 */
	void enterMembersLabel(GrammarParser.MembersLabelContext ctx);
	/**
	 * Exit a parse tree produced by the {@code MembersLabel}
	 * labeled alternative in {@link GrammarParser#members}.
	 * @param ctx the parse tree
	 */
	void exitMembersLabel(GrammarParser.MembersLabelContext ctx);
	/**
	 * Enter a parse tree produced by the {@code NonTermLabel}
	 * labeled alternative in {@link GrammarParser#curRule}.
	 * @param ctx the parse tree
	 */
	void enterNonTermLabel(GrammarParser.NonTermLabelContext ctx);
	/**
	 * Exit a parse tree produced by the {@code NonTermLabel}
	 * labeled alternative in {@link GrammarParser#curRule}.
	 * @param ctx the parse tree
	 */
	void exitNonTermLabel(GrammarParser.NonTermLabelContext ctx);
	/**
	 * Enter a parse tree produced by the {@code TermLabel}
	 * labeled alternative in {@link GrammarParser#curRule}.
	 * @param ctx the parse tree
	 */
	void enterTermLabel(GrammarParser.TermLabelContext ctx);
	/**
	 * Exit a parse tree produced by the {@code TermLabel}
	 * labeled alternative in {@link GrammarParser#curRule}.
	 * @param ctx the parse tree
	 */
	void exitTermLabel(GrammarParser.TermLabelContext ctx);
	/**
	 * Enter a parse tree produced by {@link GrammarParser#nonTermProduction}.
	 * @param ctx the parse tree
	 */
	void enterNonTermProduction(GrammarParser.NonTermProductionContext ctx);
	/**
	 * Exit a parse tree produced by {@link GrammarParser#nonTermProduction}.
	 * @param ctx the parse tree
	 */
	void exitNonTermProduction(GrammarParser.NonTermProductionContext ctx);
	/**
	 * Enter a parse tree produced by {@link GrammarParser#nodeNonTermProduction}.
	 * @param ctx the parse tree
	 */
	void enterNodeNonTermProduction(GrammarParser.NodeNonTermProductionContext ctx);
	/**
	 * Exit a parse tree produced by {@link GrammarParser#nodeNonTermProduction}.
	 * @param ctx the parse tree
	 */
	void exitNodeNonTermProduction(GrammarParser.NodeNonTermProductionContext ctx);
	/**
	 * Enter a parse tree produced by {@link GrammarParser#termProduction}.
	 * @param ctx the parse tree
	 */
	void enterTermProduction(GrammarParser.TermProductionContext ctx);
	/**
	 * Exit a parse tree produced by {@link GrammarParser#termProduction}.
	 * @param ctx the parse tree
	 */
	void exitTermProduction(GrammarParser.TermProductionContext ctx);
	/**
	 * Enter a parse tree produced by {@link GrammarParser#declRet}.
	 * @param ctx the parse tree
	 */
	void enterDeclRet(GrammarParser.DeclRetContext ctx);
	/**
	 * Exit a parse tree produced by {@link GrammarParser#declRet}.
	 * @param ctx the parse tree
	 */
	void exitDeclRet(GrammarParser.DeclRetContext ctx);
	/**
	 * Enter a parse tree produced by {@link GrammarParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(GrammarParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link GrammarParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(GrammarParser.TypeContext ctx);
}