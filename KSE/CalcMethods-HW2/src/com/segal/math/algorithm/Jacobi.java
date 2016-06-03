package com.segal.math.algorithm;

import com.segal.math.misc.DoublePrecision;
import com.segal.math.misc.Matrix;

public class Jacobi implements Algorithm {
	private Matrix approximate;
	private double eps;
	private int allowedIterations;

	private int iteration = -1;
	private double alphaNorm = 0.;

	public Jacobi(Matrix approximateResult, double eps, int iterations) {
		this.approximate = approximateResult;
		this.eps = eps;
		this.allowedIterations = iterations;
	}

	private boolean check(Matrix cur, Matrix prev) {
		return cur.subtract(prev).getVectorNorm() > (1 - alphaNorm) * eps
				/ alphaNorm;
	}

	@Override
	public Matrix run(Matrix coef, Matrix free) {
		int n = coef.getHeight();
		double[][] alpha = new double[n][n];
		double[][] beta = new double[n][1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				alpha[i][j] = (i == j ? 0. : -coef.get(i, j) / coef.get(i, i));
			}
			beta[i][0] = free.get(i, 0) / coef.get(i, i);
		}
		Matrix alphaMatrix = new Matrix(alpha);
		Matrix betaMatrix = new Matrix(beta);
		alphaNorm = alphaMatrix.getNorm();

		Matrix cur = new Matrix(approximate);
		Matrix prev;
		iteration = 0;
		do {
			iteration++;
			prev = new Matrix(cur);
			cur = alphaMatrix.multiply(prev).add(betaMatrix);
		} while (check(cur, prev) && iteration < allowedIterations);

		return new Matrix(cur);
	}

	@Override
	public String getLog() {
		if (iteration == -1) {
			System.err.println("Algorithm wasn't run!");
			return "";
		}
		StringBuilder sb = new StringBuilder();
		sb.append("Iteration: ").append(iteration).append("\n");
		sb.append(NORM + "C" + NORM + " = ")
				.append(DoublePrecision.set(alphaNorm, 3)).append("\n");
		return sb.toString();
	}

}
