package com.segal.math.algorithm;

import com.segal.math.misc.Matrix;

/**
 * author: Ruslan Sokolov date: 3/2/14
 */
public class Gauss implements Algorithm {

	@Override
	public String getLog() {
		return null;
	}

	@Override
	public Matrix run(Matrix coef, Matrix free) {
		double[][] matrix = new double[coef.getHeight()][coef.getWidth() + 1];
		for (int i = 0; i < coef.getHeight(); i++) {
			for (int j = 0; j < coef.getWidth(); j++) {
				matrix[i][j] = coef.get(i, j);
			}
		}
		for (int i = 0; i < free.getHeight(); i++) {
			matrix[i][coef.getWidth()] = free.get(i, 0);
		}

		Matrix temp = new Matrix(matrix);
		double p;
		for (int i = 0; i < temp.getHeight(); i++) {
			for (int j = 0; j < temp.getHeight(); j++) {
				if (i != j) {
					p = temp.get(j, i) / temp.get(i, i);
					for (int k = i; k <= temp.getHeight(); k++) {
						double x = temp.get(j, k) - p * temp.get(i, k);
						temp.set(j, k, x);
					}
				}
			}
		}
		double[][] answer = new double[temp.getHeight()][1];
		for (int i = 0; i < temp.getHeight(); i++) {
			answer[i][0] = temp.get(i, temp.getHeight()) / temp.get(i, i);
		}
		
		return new Matrix(answer);
	}
}
