package com.segal.math.algorithm;

import com.segal.math.misc.DoublePrecision;
import com.segal.math.misc.Matrix;

public class Relaxation implements Algorithm{
	private static final double delta = 0.05;
	
	private Matrix approximation;
	private double eps;
	private double omega = 0.05;
	private int allowedIterations;
	
	private int iteration = -1;
	private double bNorm, b1Norm, b2Norm;
	 
	public Relaxation(Matrix approximation, double eps, int allowedIterations) {
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
        
    	Matrix bestAns = approximation;
    	int bestIterations = Integer.MAX_VALUE;
    	double bestOmega = omega;
    	
    	while (omega < 2) {
    		Matrix b1Cur = new Matrix(b1);
            Matrix b2Cur = new Matrix(b2);
            Matrix cCur = new Matrix(c);
            b1Cur = b1Cur.scale(omega);
            b2Cur = b2Cur.scale(omega);
            cCur = cCur.scale(omega);
            for (int i = 0; i < b1Cur.getHeight(); i++) {
                for (int j = 0; j < i; j++) {
                    ieb.set(i, j, -b1Cur.get(i, j));
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
	            cur = ieb.multiply(b2Cur.multiply(prev).add(cCur).add(prev.scale(1. - omega)));
	        } while (!itIsTimeToStop(cur, prev));
	        if (iteration < bestIterations) {
	        	bestIterations = iteration;
	        	bestOmega = omega;
	        	bestAns = cur;
	        }
	        omega += delta;
	    }
    	omega = bestOmega;
    	iteration = bestIterations;
        return bestAns;
    }

    @Override
    public String getLog() {
        if (iteration == -1) {
            System.err.println("Relaxation algorithm wasn't run!");
            return "";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("Iteration: " + iteration + "\n");
        sb.append(NORM + "C1" + NORM + " + " + NORM + "C2" + NORM + " = " + DoublePrecision.set(b1Norm + b2Norm, 3)
                + "\n");
        sb.append("ω = " + DoublePrecision.set(omega, 3) + "\n");
        return sb.toString();
    }
	
}

/*
6.25 -1 0.5
-1 5 2.12
0.5 2.12 3.6

7.5
-8.68
-0.24
*/