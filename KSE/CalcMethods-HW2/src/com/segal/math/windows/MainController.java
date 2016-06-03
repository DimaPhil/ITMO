package com.segal.math.windows;

import java.io.IOException;
import java.net.URL;
import java.util.Arrays;
import java.util.Random;
import java.util.ResourceBundle;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import com.segal.math.misc.Checker;
import com.segal.math.misc.Matrix;
import com.segal.math.misc.DoublePrecision;
import com.segal.math.algorithm.Algorithm;
import com.segal.math.algorithm.ConjugateGradient;
import com.segal.math.algorithm.Gauss;
import com.segal.math.algorithm.Relaxation;
import com.segal.math.algorithm.Seidel;
import com.segal.math.algorithm.Jacobi;

public class MainController implements Initializable {

	static final private String VECTOR = "Vector:\n";
	static final private String CHECK = "Check:\n";

	@FXML
	private Label condNumber = new Label();
	@FXML
	private TextField numberOfIterations = new TextField();
	@FXML
	private TextField epsValue = new TextField();
	@FXML
	private TextArea matrixField = new TextArea();
	@FXML
	private TextArea vectorField = new TextArea();
	@FXML
	private TextArea approximationField = new TextArea();
	@FXML
	private TextField matrixSize = new TextField();
	@FXML
	private Button saveButton = new Button();
	@FXML
	private ChoiceBox<String> matrixType = new ChoiceBox<>();

	@FXML
	private TextArea gaussResult = new TextArea();
	@FXML
	private TextArea gaussLog = new TextArea();
	@FXML
	private TextArea jacobiResult = new TextArea();
	@FXML
	private TextArea jacobiLog = new TextArea();
	@FXML
	private TextArea seidelResult = new TextArea();
	@FXML
	private TextArea seidelLog = new TextArea();
	@FXML
	private TextArea relaxationResult = new TextArea();
	@FXML
	private TextArea relaxationLog = new TextArea();
	@FXML
	private TextArea gradientResult = new TextArea();
	@FXML
	private TextArea gradientLog = new TextArea();

	private Matrix[] results = new Matrix[5];
	private boolean[] curMode = new boolean[5];

	private Matrix coef, free;

	@Override
	public void initialize(URL arg0, ResourceBundle arg1) {
		numberOfIterations.addEventFilter(KeyEvent.KEY_TYPED,
				new OnlyPositiveInteger());
		epsValue.addEventFilter(KeyEvent.KEY_TYPED, new OnlyPositiveInteger());
		matrixField.addEventFilter(KeyEvent.KEY_TYPED, new OnlyDouble());
		vectorField.addEventFilter(KeyEvent.KEY_TYPED, new OnlyDouble());
		approximationField.addEventFilter(KeyEvent.KEY_TYPED, new OnlyDouble());
	}

	@FXML
	private void calculateResult(ActionEvent event) {
		try {
			Arrays.fill(curMode, false);
			Matrix approximate;
			try {
				coef = new Matrix(matrixField.getText());
				condNumber.setText("Cond: "
						+ DoublePrecision.set(coef.getInverse().getNorm()
								* coef.getNorm(), 3));
				free = new Matrix(vectorField.getText());
				approximate = new Matrix(approximationField.getText());
			} catch (NumberFormatException e) {
				System.err.println(e.getMessage());
				return;
			}

			/*if (Math.abs(coef.getDeterminant()) < 0.1E-15) {
				Stage dialog = new Stage();
				dialog.initStyle(StageStyle.UTILITY);
				Scene scene = new Scene(new Group(new Text(10, 15,
						"Singular matrix!")), 100, 20);
				dialog.setScene(scene);
				dialog.setResizable(false);
				dialog.setTitle("ERROR");
				dialog.show();
				return;
			}*/

			final Matrix app = new Matrix(approximate);
			final double eps = Double.parseDouble(epsValue.getText());
			final int iter = Integer.parseInt(numberOfIterations.getText());

			final Algorithm gauss = new Gauss();
			final Algorithm jacobi = new Jacobi(app, eps, iter);
			final Algorithm seidel = new Seidel(app, eps, iter);
			final Algorithm relaxation = new Relaxation(app, eps, iter);
			final Algorithm gradient = new ConjugateGradient(app, eps);

			Thread th[] = new Thread[5];
			th[0] = new Thread(new Runnable() {
				@Override
				public void run() {
					int cur = 0;
					long time = System.nanoTime();
					results[cur] = gauss.run(coef, free);
					if (results[cur] != null) {
						for (int j = 0; j < results[cur].getHeight(); j++) {
							results[cur].set(j, 0, DoublePrecision.set(
									results[cur].get(j, 0),
									DoublePrecision.getPrecision(eps)));
						}
					}
					gaussResult.setText(VECTOR + results[cur]);
					gaussLog.setText(gauss.getLog());
					System.out.println("Time gauss: "
							+ (System.nanoTime() - time));
				}
			});
			th[1] = new Thread(new Runnable() {
				@Override
				public void run() {
					int cur = 1;
					long time = System.nanoTime();
					results[cur] = jacobi.run(coef, free);
					if (results[cur] != null) {
						for (int j = 0; j < results[cur].getHeight(); j++) {
							results[cur].set(j, 0, DoublePrecision.set(
									results[cur].get(j, 0),
									DoublePrecision.getPrecision(eps)));
						}
					}
					jacobiResult.setText(VECTOR + results[cur]);
					jacobiLog.setText(jacobi.getLog());
					System.out.println("Time jacobi: "
							+ (System.nanoTime() - time));
				}
			});
			th[2] = new Thread(new Runnable() {
				@Override
				public void run() {
					int cur = 2;
					long time = System.nanoTime();
					results[cur] = seidel.run(coef, free);
					if (results[cur] != null) {
						for (int j = 0; j < results[cur].getHeight(); j++) {
							results[cur].set(j, 0, DoublePrecision.set(
									results[cur].get(j, 0),
									DoublePrecision.getPrecision(eps)));
						}
					}
					seidelResult.setText(VECTOR + results[cur]);
					seidelLog.setText(seidel.getLog());
					System.out.println("Time seidel: "
							+ (System.nanoTime() - time));
				}
			});
			th[3] = new Thread(new Runnable() {
				@Override
				public void run() {
					int cur = 3;
					long time = System.nanoTime();
					results[cur] = relaxation.run(coef, free);
					if (results[cur] != null) {
						for (int j = 0; j < results[cur].getHeight(); j++) {
							results[cur].set(j, 0, DoublePrecision.set(
									results[cur].get(j, 0),
									DoublePrecision.getPrecision(eps)));
						}
					}
					relaxationResult.setText(VECTOR + results[cur]);
					relaxationLog.setText(relaxation.getLog());
					System.out.println("Time relaxation: "
							+ (System.nanoTime() - time));
				}
			});
			th[4] = new Thread(new Runnable() {
				@Override
				public void run() {
					int cur = 4;
					long time = System.nanoTime();
					results[cur] = gradient.run(coef, free);
					if (results[cur] != null) {
						for (int j = 0; j < results[cur].getHeight(); j++) {
							results[cur].set(j, 0, DoublePrecision.set(
									results[cur].get(j, 0),
									DoublePrecision.getPrecision(eps)));
						}
					}
					gradientResult.setText(VECTOR + results[cur]);
					gradientLog.setText(gradient.getLog());
					System.out.println("Time gradient: "
							+ (System.nanoTime() - time));
				}
			});

			for (Thread t : th) {
				t.start();
			}

			for (Thread t : th) {
				try {
					t.join();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			System.out.println("----------------------------------");

		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	@FXML
	private void generateMatrix(ActionEvent event) {
		if (matrixSize.getText().matches("[0-9]+")) {
			int size = Integer.parseInt(matrixSize.getText());
			Random rand = new Random();
			StringBuilder newMatrix = new StringBuilder();
			StringBuilder newVector = new StringBuilder();
			StringBuilder newApproximation = new StringBuilder();
			if (!matrixType.getValue().equals("Symmetric")) {
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						if (matrixType.getValue().equals("Random")) {
							newMatrix.append(DoublePrecision.set(
									rand.nextDouble(), 3));
						} else {
							if (matrixType.getValue().equals("Hilbert matrix")) {
								newMatrix.append(1. / (i + j + 1));
							} else {
								newMatrix.append(i != j ? DoublePrecision.set(
										rand.nextDouble(), 3) : DoublePrecision
										.set(10. + rand.nextInt(50)
												+ rand.nextDouble(), 3));
							}
						}
						newMatrix.append(" ");
					}
					newMatrix.append("\n");
				}
			} else {
				Matrix sim = new Matrix(size, size);
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						sim.set(i, j, rand.nextInt(100));
					}
				}
				sim = sim.transpose().multiply(sim);
				newMatrix.append(sim.toString());
			}
			for (int i = 0; i < size; i++) {
				newVector.append(DoublePrecision.set(rand.nextDouble(), 3)
						+ "\n");
				newApproximation.append(DoublePrecision.set(rand.nextDouble(),
						3) + "\n");
			}

			matrixField.setText(newMatrix.toString());
			vectorField.setText(newVector.toString());
			approximationField.setText(newApproximation.toString());
		} else {
			Stage dialog = new Stage();
			dialog.initStyle(StageStyle.UTILITY);
			Scene scene = new Scene(new Group(new Text(10, 15,
					"Incorrect matrix size!")), 130, 20);
			dialog.setScene(scene);
			dialog.setResizable(false);
			dialog.setTitle("ERROR");
			dialog.show();
		}
	}

	@FXML
	private void gaussResultClick(MouseEvent me) {
		int curMethod = 0;
		if (me.getButton().equals(MouseButton.PRIMARY)) {
			if (coef == null || free == null || results[curMethod] == null) {
				return;
			}
			if (curMode[curMethod]) {
				curMode[curMethod] = false;
				gaussResult.setText(VECTOR + results[curMethod]);
			} else {
				curMode[curMethod] = true;
				gaussResult.setText(CHECK
						+ Checker.getResult(coef, free, results[curMethod]));
			}
		}
	}

	@FXML
	private void jacobiResultClick(MouseEvent me) {
		int curMethod = 1;
		if (me.getButton().equals(MouseButton.PRIMARY)) {
			if (coef == null || free == null || results[curMethod] == null) {
				return;
			}
			if (curMode[curMethod]) {
				curMode[curMethod] = false;
				jacobiResult.setText(VECTOR + results[curMethod]);
			} else {
				curMode[curMethod] = true;
				jacobiResult.setText(CHECK
						+ Checker.getResult(coef, free, results[curMethod]));
			}
		}
	}

	@FXML
	private void seidelResultClick(MouseEvent me) {
		int curMethod = 2;
		if (me.getButton().equals(MouseButton.PRIMARY)) {
			if (coef == null || free == null || results[curMethod] == null) {
				return;
			}
			if (curMode[curMethod]) {
				curMode[curMethod] = false;
				seidelResult.setText(VECTOR + results[curMethod]);
			} else {
				curMode[curMethod] = true;
				seidelResult.setText(CHECK
						+ Checker.getResult(coef, free, results[curMethod]));
			}
		}
	}

	@FXML
	private void relaxationResultClick(MouseEvent me) {
		int curMethod = 3;
		if (me.getButton().equals(MouseButton.PRIMARY)) {
			if (coef == null || free == null || results[curMethod] == null) {
				return;
			}
			if (curMode[curMethod]) {
				curMode[curMethod] = false;
				relaxationResult.setText(VECTOR + results[curMethod]);
			} else {
				curMode[curMethod] = true;
				relaxationResult.setText(CHECK
						+ Checker.getResult(coef, free, results[curMethod]));
			}
		}
	}

	@FXML
	private void gradientResultClick(MouseEvent me) {
		int curMethod = 4;
		if (me.getButton().equals(MouseButton.PRIMARY)) {
			if (coef == null || free == null || results[curMethod] == null) {
				return;
			}
			if (curMode[curMethod]) {
				curMode[curMethod] = false;
				gradientResult.setText(VECTOR + results[curMethod]);
			} else {
				curMode[curMethod] = true;
				gradientResult.setText(CHECK
						+ Checker.getResult(coef, free, results[curMethod]));
			}
		}
	}

	private class OnlyPositiveInteger implements EventHandler<KeyEvent> {
		@Override
		public void handle(KeyEvent event) {
			String character = event.getCharacter();

			if (!character.matches("[0-9 \n]"))
				event.consume();
		}
	}

	private class OnlyDouble implements EventHandler<KeyEvent> {
		@Override
		public void handle(KeyEvent event) {
			String character = event.getCharacter();

			if (!character.matches("[0-9. \n-]"))
				event.consume();
		}
	}
}
