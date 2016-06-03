package com.segal.math.misc;

public class Checker {

	static public boolean isCorrectResult(Matrix coef, Matrix free,
			Matrix result, double eps) {
		int n = coef.getHeight();
		for (int i = 0; i < n; i++) {
			double res = 0.;
			for (int j = 0; j < n; j++) {
				res += (coef.get(i, j) * result.get(i, 0));
			}
			if (Double.isInfinite(res) || Double.isNaN(res)
					|| Math.abs(res - free.get(i, 0)) > eps) {
				return false;
			}
		}
		return true;
	}

	static public Matrix getResult(Matrix coef, Matrix free, Matrix result) {
		int n = coef.getHeight();
		double[][] newResult = new double[n][1];
		for (int i = 0; i < n; i++) {
			double res = 0.;
			for (int j = 0; j < n; j++) {
				res += (coef.get(i, j) * result.get(j, 0));
			}
			newResult[i][0] = (res - free.get(i, 0));
		}
		return new Matrix(newResult);
	}

}
