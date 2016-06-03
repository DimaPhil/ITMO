package com.segal.math.windows;

import java.io.IOException;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {
	public static void main(String[] args) {
		launch(args);
	}

	@Override
	public void start(Stage stage) {
		try {
			Parent root = FXMLLoader.load(getClass().getResource(
					"MainView.fxml"));
			stage.setScene(new Scene(root));
			stage.setResizable(false);
			stage.setTitle("Matrix");
			stage.show();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
