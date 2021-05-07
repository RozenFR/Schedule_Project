package application;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import controller.ScheduleController;

import java.io.IOException;

public class App extends Application {

    public static void main(String [] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws IOException {
        // Setup FXML
        FXMLLoader loader = new FXMLLoader(getClass().getResource("../view/Schedule.fxml"));
        Parent view = loader.load();
        view.getStylesheets().add(getClass().getResource("application.css").toExternalForm());

        stage.setTitle("Scheduling");

        stage.setScene(new Scene(view));
        stage.show();
    }
}