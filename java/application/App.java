package application;

import controller.ScheduleController;
import javafx.application.Application;
import javafx.event.*;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import model.ScheduleModel;
import view.ScheduleView;

public class App extends Application {
    public static void main(String [] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {
        // Setup
        ScheduleModel schedModel = new ScheduleModel();
        ScheduleController schedController = new ScheduleController(schedModel);
        ScheduleView schedView = new ScheduleView(schedController, schedModel);

        stage.setScene(new Scene(schedView.AsParent(), 500, 500));
        stage.show();
    }
}