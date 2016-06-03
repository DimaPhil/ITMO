package com.segal.math.misc;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Matrix {
	private double[][] matrix;
	private int width;
	private int height;

	public Matrix(File file) throws IOException {
		try (BufferedReader in = new BufferedReader(new FileReader(file))) {
			ArrayList<ArrayList<Double>> mat = new ArrayList<>();
			String line = "";
			while ((line = in.readLine()) != null) {
				ArrayList<Double> row = new ArrayList<>();
				StringTokenizer st = new StringTokenizer(line, " ");
				while (st.hasMoreTokens()) {
					row.add(Double.parseDouble(st.nextToken()));
				}
				mat.add(row);
			}
			matrix = new double[mat.size()][mat.get(0).size()];
			for (int i = 0; i < matrix.length; i++) {
				for (int j = 0; j < matrix[0].length; j++) {
					matrix[i][j] = mat.get(i).get(j);
				}
			}
			height = matrix.length;
			width = matrix[0].length;
		}
	}

	public Matrix(String stringMatrix) throws IOException {
		ArrayList<ArrayList<Double>> mat = new ArrayList<>();
		StringTokenizer stLine = new StringTokenizer(stringMatrix, "\n");
		while (stLine.hasMoreTokens()) {
			String line = stLine.nextToken();
			ArrayList<Double> row = new ArrayList<>();
			StringTokenizer st = new StringTokenizer(line, " ");
			while (st.hasMoreTokens()) {
				row.add(Double.parseDouble(st.nextToken()));
			}
			mat.add(row);
		}
		matrix = new double[mat.size()][mat.get(0).size()];
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[0].length; j++) {
				matrix[i][j] = mat.get(i).get(j);
			}
		}
		height = matrix.length;
		width = matrix[0].length;
	}

	public Matrix(int height, int width) {
		this.height = height;
		this.width = width;
		this.matrix = new double[height][width];
	}

	public Matrix(double[][] matrix) {
		this.height = matrix.length;
		this.width = matrix[0].length;
		this.matrix = new double[height][width];
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				this.matrix[y][x] = matrix[y][x];
			}
		}
	}

	public Matrix(Matrix matrix) {
		this.height = matrix.getHeight();
		this.width = matrix.getWidth();
		this.matrix = new double[this.height][this.width];
		for (int x = 0; x < this.height; x++) {
			for (int y = 0; y < this.width; y++) {
				this.matrix[x][y] = matrix.get(x, y);
			}
		}
	}

	public int getWidth() {
		return width;
	}

	public int getHeight() {
		return height;
	}

	public double getNorm() {
		double res = 0.;
		for (int i = 0; i < matrix.length; i++) {
			double cur = 0.;
			for (int j = 0; j < matrix[0].length; j++) {
				cur += Math.abs(matrix[i][j]);
			}
			res = Math.max(cur, res);
		}
		return res;
	}

	public double getVectorNorm() {
		double res = 0.;
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[0].length; j++) {
				res = Math.max(res, Math.abs(matrix[i][j]));
			}
		}
		return res;
	}

	public Matrix add(Matrix a) {
		Matrix ans = new Matrix(height, width);
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				ans.matrix[y][x] = matrix[y][x] + a.matrix[y][x];
			}
		}
		return ans;
	}

	public Matrix subtract(Matrix a) {
		Matrix ans = new Matrix(height, width);
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				ans.matrix[y][x] = matrix[y][x] - a.matrix[y][x];
			}
		}
		return ans;
	}

	public Matrix multiply(Matrix a) {
		Matrix ans = new Matrix(height, a.width);
		for (int x = 0; x < ans.height; x++) {
			for (int y = 0; y < ans.width; y++) {
				for (int k = 0; k < width; k++) {
					ans.matrix[x][y] += (matrix[x][k] * a.matrix[k][y]);
				}
			}
		}
		return ans;
	}

	public Matrix scale(double n) {
		Matrix ans = new Matrix(height, width);
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				ans.matrix[y][x] = matrix[y][x] * n;
			}
		}
		return ans;
	}

	public Matrix transpose() {
		Matrix ans = new Matrix(width, height);
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				ans.matrix[x][y] = matrix[y][x];
			}
		}
		return ans;
	}

	public double getDeterminant() {
		return recursiveDeterminant(new Matrix(matrix));
	}

	private double recursiveDeterminant(Matrix matrix) {
		int n = matrix.getHeight();
		if (n == 1) {
			return matrix.get(0, 0);
		}
		double res = 0.;
		for (int i = 0; i < n; i++) {
			Matrix newMatrix = new Matrix(n - 1, n - 1);
			for (int j = 0; j < n; j++) {
				for (int k = 1; k < n; k++) {
					if (j != i) {
						newMatrix.set(j < i ? j : j - 1, k - 1, matrix.get(j, k));
					}
				}
			}
			res += ((i % 2 == 0 ? 1 : -1) * matrix.get(i, 0) * recursiveDeterminant(newMatrix));
		}
		return res;
	}

	public Matrix getInverse() {
		double[][] e = new double[height][height];
		double[][] clone = new double[height][height];
		for (int i = 0; i < e.length; i++) {
			for (int j = 0; j < e.length; j++) {
				e[i][j] = (i == j ? 1 : 0);
				clone[i][j] = matrix[i][j];
			}
		}

		for (int index = 0; index < clone.length; index++) {
			if (clone[index][index] == 0.) {
				for (int j = index + 1; j < clone.length; j++) {
					if (clone[j][index] != 0.) {
						double[] row = clone[index];
						clone[index] = clone[j];
						clone[j] = row;
						break;
					}
				}
			}
			double del = clone[index][index];
			for (int j = 0; j < clone.length; j++) {
				clone[index][j] /= del;
				e[index][j] /= del;
			}

			for (int i = 0; i < clone.length; i++) {
				if (index == i) {
					continue;
				}
				double mul = clone[i][index];
				for (int j = 0; j < clone.length; j++) {
					clone[i][j] -= (mul * clone[index][j]);
					e[i][j] -= (mul * e[index][j]);
				}
			}
		}

		return new Matrix(e);
	}

	public double get(int i, int j) {
		return matrix[i][j];
	}

	public double set(int i, int j, double val) {
		return matrix[i][j] = val;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				sb.append(matrix[i][j] + " ");
			}
			sb.append("\n");
		}
		return sb.toString();
	}
}
