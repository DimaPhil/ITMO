package com.segal.math.algorithm;

import com.segal.math.misc.Matrix;

/**
 * Created by warrior on 03.03.14.
 */
public class ConjugateGradient implements Algorithm {

    private Matrix matrix;
    private Matrix free;
    private Matrix approximation;
    private double eps;

    public ConjugateGradient(Matrix approximation, double eps) {
        this.approximation = approximation;
        this.eps = eps;
    }

    @Override
    public String getLog() {
        return null;
    }

    @Override
    public Matrix run(Matrix matrix, Matrix free) {
        if (matrix.getWidth() != matrix.getHeight()) {
            throw new IllegalArgumentException("matrix width != matrix height");
        }
        if (free.getWidth() != 1) {
            throw new IllegalArgumentException("width != 1");
        }
        if (free.getHeight() != matrix.getWidth()) {
            throw new IllegalArgumentException("free height != matrix width");
        }
        this.matrix = matrix;
        this.free = free;
        Matrix curGradient = getGradient(approximation);
        Matrix curP = curGradient.scale(-1);
        Matrix curRes = new Matrix(approximation);
        for (int i = 0; i < matrix.getWidth(); i++) {
            if (less(curRes)) {
                break;
            }
            curRes = curRes.add(curP.scale(alpha(curP, curGradient)));
            curGradient = getGradient(curRes);
            curP = nextP(curP, curGradient);
        }
        return curRes;
    }

    private static double scalarProduct(Matrix a, Matrix b) {
        if (a.getWidth() != 1 || b.getWidth() != 1) {
            throw new IllegalArgumentException("width != 1");
        }
        if (a.getHeight() != b.getHeight()) {
            throw new IllegalArgumentException("a.getHeight() != b.getHeight()");
        }
        double res = 0;
        for (int i = 0; i < a.getHeight(); i++) {
            res += a.get(i, 0) * b.get(i, 0);
        }
        return res;
    }

    private Matrix getGradient(Matrix arg) {
        return matrix.multiply(arg).subtract(free);
    }

    private double alpha(Matrix p, Matrix gradient) {
        return -scalarProduct(gradient, p) / scalarProduct(matrix.multiply(p), p);
    }

    private double betta(Matrix p, Matrix gradient) {
        Matrix matrixOnP = matrix.multiply(p);
        return scalarProduct(matrixOnP, gradient) / scalarProduct(matrixOnP, p);
    }

    private Matrix nextP(Matrix currentP, Matrix gradient) {
        return currentP.scale(betta(currentP, gradient)).subtract(gradient);
    }

    private boolean less(Matrix v) {
        Matrix diff = getGradient(v);
        for (int i = 0; i < diff.getHeight(); i++) {
            if (Math.abs(diff.get(i, 0)) > eps) {
                return false;
            }
        }
        return true;
    }
}
