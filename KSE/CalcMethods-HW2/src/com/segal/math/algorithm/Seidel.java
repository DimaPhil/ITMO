package com.segal.math.algorithm;

import com.segal.math.misc.DoublePrecision;
import com.segal.math.misc.Matrix;

public class Seidel implements Algorithm {
    private Matrix approximation;
    private double eps;
    private int allowedIterations;

    private int iteration = -1;
    private double bNorm, b1Norm, b2Norm;

    public Seidel(Matrix approximation, double eps, int allowedIterations) {
        this.approximation = approximation;
        this.eps = eps;
        this.allowedIterations = allowedIterations;
    }

    private boolean itIsTimeToStop(Matrix cur, Matrix prev) {
        if (iteration >= allowedIterations) {
            return true;
        }
        return cur.subtract(prev).getVectorNorm() <= (1 - bNorm) / b2Norm * eps;
    }

    @Override
    public Matrix run(Matrix coef, Matrix free) {
        assert(free.getWidth() == 1);
        Matrix b1 = new Matrix(coef.getHeight(), coef.getWidth());
        Matrix b2 = new Matrix(coef.getHeight(), coef.getWidth());
        Matrix ieb = new Matrix(coef.getHeight(), coef.getWidth());
        Matrix c = new Matrix(coef.getHeight(), 1);
        for (int i = 0; i < coef.getHeight(); i++) {
            for (int j = 0; j < coef.getWidth(); j++) {
                if (i == j) {
                    b1.set(i, j, 0);
                } else {
                    b1.set(i, j, -coef.get(i, j) / coef.get(i, i));
                }
            }
            c.set(i, 0, free.get(i, 0) / coef.get(i, i));
        }
        bNorm = b1.getNorm();
        for (int i = 0; i < b1.getHeight(); i++) {
            for (int j = i + 1; j < b1.getWidth(); j++) {
                b2.set(i, j, b1.get(i, j));
                b1.set(i, j, 0);
            }
        }
        b1Norm = b1.getNorm();
        b2Norm = b2.getNorm();
        for (int i = 0; i < b1.getHeight(); i++) {
            for (int j = 0; j < i; j++) {
                ieb.set(i, j, -b1.get(i, j));
            }
            ieb.set(i, i, 1);
        }
        ieb = ieb.getInverse();
        Matrix prev;
        Matrix cur = approximation;
        iteration = 0;
        do {
            iteration++;
            prev = cur;
            cur = ieb.multiply(b2.multiply(prev).add(c));
        } while (!itIsTimeToStop(cur, prev));
        
        return cur;
    }

    @Override
    public String getLog() {
        if (iteration == -1) {
            System.err.println("Seidel algorithm wasn't run!");
            return "";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("Iteration: " + iteration + "\n");
        sb.append(NORM + "C1" + NORM + " + " + NORM + "C2" + NORM + " = " + DoublePrecision.set(b1Norm + b2Norm, 3)
                + "\n");
        return sb.toString();
    }
}
