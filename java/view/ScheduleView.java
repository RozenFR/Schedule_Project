package view;

import controller.ScheduleController;
import javafx.scene.Parent;
import javafx.scene.layout.VBox;
import model.ScheduleModel;

public class ScheduleView {
    private VBox root;

    public ScheduleView(ScheduleController schedController, ScheduleModel schedModel) {
    }

    public Parent AsParent() {
        return this.root;
    }
}
