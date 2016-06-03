package com.segal.math.algorithm;

import com.segal.math.misc.Matrix;

public interface Algorithm {

	static final String NORM = "‖";

	public String getLog();

	public Matrix run(Matrix coef, Matrix free);

}
