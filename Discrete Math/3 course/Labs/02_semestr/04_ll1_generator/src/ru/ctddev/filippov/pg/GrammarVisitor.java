// Generated from /home/dmitry/Documents/work/git/pg/Grammar.g4 by ANTLR 4.5.1

package ru.ctddev.filippov.pg;

import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link GrammarParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface GrammarVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link GrammarParser#main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMain(GrammarParser.MainContext ctx);
	/**
	 * Visit a parse tree produced by the {@code HeaderLabel}
	 * labeled alternative in {@link GrammarParser#header}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitHeaderLabel(GrammarParser.HeaderLabelContext ctx);
	/**
	 * Visit a parse tree produced by the {@code MembersLabel}
	 * labeled alternative in {@link GrammarParser#members}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMembersLabel(GrammarParser.MembersLabelContext ctx);
	/**
	 * Visit a parse tree produced by the {@code NonTermLabel}
	 * labeled alternative in {@link GrammarParser#curRule}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNonTermLabel(GrammarParser.NonTermLabelContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TermLabel}
	 * labeled alternative in {@link GrammarParser#curRule}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTermLabel(GrammarParser.TermLabelContext ctx);
	/**
	 * Visit a parse tree produced by {@link GrammarParser#nonTermProduction}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNonTermProduction(GrammarParser.NonTermProductionContext ctx);
	/**
	 * Visit a parse tree produced by {@link GrammarParser#nodeNonTermProduction}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNodeNonTermProduction(GrammarParser.NodeNonTermProductionContext ctx);
	/**
	 * Visit a parse tree produced by {@link GrammarParser#termProduction}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTermProduction(GrammarParser.TermProductionContext ctx);
	/**
	 * Visit a parse tree produced by {@link GrammarParser#declRet}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeclRet(GrammarParser.DeclRetContext ctx);
	/**
	 * Visit a parse tree produced by {@link GrammarParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType(GrammarParser.TypeContext ctx);
}