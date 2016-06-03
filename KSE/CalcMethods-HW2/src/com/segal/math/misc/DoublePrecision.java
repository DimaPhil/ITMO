package com.segal.math.misc;

import java.math.BigDecimal;

public class DoublePrecision {
	public static int getPrecision(double eps) {
		if (Double.isNaN(eps) || Double.isInfinite(eps)) {
			return -1;
		}
		int precision = 1;
		while (eps * 10 < 1.) {
			eps *= 10;
			precision++;
		}
		return precision;
	}

	public static Double set(Double value, int precision) {
		if (Double.isNaN(value) || Double.isInfinite(value)) {
			return value;
		}
		return new BigDecimal(value).setScale(precision,
				BigDecimal.ROUND_HALF_UP).doubleValue();
	}
}
