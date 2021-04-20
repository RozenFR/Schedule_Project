package controller;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TableView;
import javafx.stage.FileChooser;
import model.ScheduleModel;

import java.io.File;
import java.net.URL;
import java.util.ResourceBundle;

public class ScheduleController {

    // FXML Variable
    @FXML private Label _input;
    @FXML private Label _output;

    @FXML private Label _Makespan;
    @FXML private Label _WJCJ;
    @FXML private Label _WJFJ;
    @FXML private Label _WJTJ;

    @FXML private TableView _tableView;

    // Choix de la structure et du modèle d'ordre
    @FXML private RadioButton _rOL;
    @FXML private RadioButton _rBST;
    @FXML private RadioButton _rEBST;
    @FXML private RadioButton _rSPT;
    @FXML private RadioButton _rLPT;
    @FXML private RadioButton _rWSPT;
    @FXML private RadioButton _rFCFS;

    // BackFilling
    @FXML private RadioButton _rbf;
    @FXML private RadioButton _rnbf;


    private ScheduleModel schedModel;

    public ScheduleController() {

    }

    public void initialize() {

    }

    // Setter
    private void SetModel(ScheduleModel schedModel) {
        this.schedModel = schedModel;
    }

    public void SetSchedule(String input, String output, int dt, int ord, int bf) {
        GetModel().getSchedule(input, output, dt, ord, bf);
    }

    // Getter
    private ScheduleModel GetModel() {
        return this.schedModel;
    }

    // SetInput
    @FXML
    public void SetInput() {
        FileChooser file = new FileChooser();
        file.setTitle("Selection du fichier entrant.");
        File selectedFile = file.showOpenDialog(null);
        this._input.setText(selectedFile.toString());
    }

    // Set Output
    @FXML
    public void SetOutput() {
        FileChooser file = new FileChooser();
        file.setTitle("Selection du fichier entrant.");
        File selectedFile = file.showOpenDialog(null);
        this._output.setText(selectedFile.toString());
    }


    // Management of the Schedule data
    @FXML
    public void Exec_Schedule() {
        if (_rOL.isSelected()) {
            if (_rSPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(null, null, 0, 0, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(null, null, 0, 0, 0);
            }
            else if (_rLPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(null, null, 0, 0, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(null, null, 0, 0, 0);
            }
            else if (_rWSPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(null, null, 0, 0, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(null, null, 0, 0, 0);
            }
            else if (_rFCFS.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(null, null, 0, 0, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(null, null, 0, 0, 0);
            }
        }
    }


}
