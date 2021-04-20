package view;

import controller.ScheduleController;
import javafx.scene.Parent;
import javafx.scene.layout.VBox;
import model.ScheduleModel;

public class ScheduleView {

    // Controller and Model
    private ScheduleController scheduleController;
    private ScheduleModel scheduleModel;

    private VBox root;

    public ScheduleView(ScheduleController schedController, ScheduleModel schedModel) {

        SetController(schedController);
        SetModel(schedModel);

    }

    // Setter
    private void SetController(ScheduleController controller) {
        this.scheduleController = controller;
    }

    private void SetModel(ScheduleModel model) {
        this.scheduleModel = model;
    }

    // Getter
    public ScheduleController GetController() {
        return this.scheduleController;
    }

    public ScheduleModel GetModel() {
        return this.scheduleModel;
    }

    // Method for JavaFX
    public Parent AsParent() {
        return this.root;
    }
}
