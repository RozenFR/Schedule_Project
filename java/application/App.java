package application;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class App extends Application {

    public static void main(String [] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws IOException {
        // Setup FXML
        FXMLLoader loader = new FXMLLoader(getClass().getResource("../view/Schedule.fxml"));
        HBox view = loader.load();

        stage.setScene(new Scene(view));
        stage.show();
    }
}