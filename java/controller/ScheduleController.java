package controller;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import model.ScheduleModel;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

public class ScheduleController {

    // FXML Variable
    @FXML private Label _input;
    @FXML private Label _output;

    @FXML private Label _Makespan;
    @FXML private Label _WJCJ;
    @FXML private Label _WJFJ;
    @FXML private Label _WJTJ;

    @FXML private AnchorPane _diagram;
    @FXML private HBox _ViewContent;

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

    public ScheduleController() {
    }

    @FXML
    public void initialize() {

    }

    // Setter
    private void SetSchedule(String input, String output, int dt, int ord, int bf) {
        if (input.isBlank())
            throw new NullPointerException("SetSchedule NullPointerException : input is blank.");
        if (output.isBlank())
            throw new NullPointerException("SetSchedule NullPointerException : output is blank.");
        if (dt < 0 || dt > 2)
            throw new NullPointerException("SetSchedule NullPointerException : DataStructure need to be between 0 and 2 included.");
        if (ord < 0 || ord > 3)
            throw new NullPointerException("SetSchedule NullPointerException : Order need to be between 0 and 3 included.");
        if (bf != 0 && bf != 1)
            throw new NullPointerException("SetSchedule NullPointerException : BackFilling need to be 0 or 1.");
        System.out.println(input);
        System.out.println(output);
        new ScheduleModel().getSchedule(input, output, dt, ord, bf);
    }

    @FXML
    private void SetInput() {
        FileChooser file = new FileChooser();
        file.setTitle("Selection du fichier entrant.");
        File selectedFile = file.showOpenDialog(null);
        if (selectedFile != null)
            GetInput().setText(selectedFile.toString());
    }

    @FXML
    private void SetOutput() throws Exception {
        FileChooser file = new FileChooser();
        file.setTitle("Selection du fichier Sortant.");
        File selectedFile = file.showOpenDialog(null);
        if (selectedFile != null)
            GetOutput().setText(selectedFile.toString());

        if (!GetInput().getText().isBlank())
            Exec_Schedule();
    }

    private void SetMakespan(long makespan) throws Exception {
        if (makespan < 0) {
            GetMakespan().setText("Erreur de calcul ...");
            throw new Exception("SetMakespan <variable> : makespan can't be negative.");
        }
        GetMakespan().setText(LongToStr(makespan));
    }

    private void SetWjCj(long wjcj) throws Exception {
        if (wjcj < 0) {
            GetWjCj().setText("Erreur de calcul ...");
            throw new Exception("SetWjCj <variable> : wjcj can't be negative.");
        }
        GetWjCj().setText(LongToStr(wjcj));
    }

    private void SetWjTj(long wjtj) throws Exception {
        if (wjtj < 0) {
            GetWjTj().setText("Erreur de calcul ...");
            throw new Exception("SetWjTj <variable> : wjtj can't be negative.");
        }
        GetWjTj().setText(LongToStr(wjtj));
    }

    private void SetWjFj(long wjfj) throws Exception {
        if (wjfj < 0) {
            GetWjFj().setText("Erreur de calcul ...");
            throw new Exception("SetWjFj <variable> : wjfj can't be negative.");
        }
        GetWjFj().setText(LongToStr(wjfj));
    }

    // Getter
    public AnchorPane GetDiagram() {
        return this._diagram;
    }

    public HBox GetViewContent() {
        return this._ViewContent;
    }
    
    public Label GetInput() {
        return this._input;
    }

    public Label GetOutput() {
        return this._output;
    }

    public Label GetMakespan() {
        return this._Makespan;
    }

    public Label GetWjCj() {
        return this._WJCJ;
    }

    public Label GetWjTj() {
        return this._WJTJ;
    }

    public Label GetWjFj() {
        return this._WJFJ;
    }

    public RadioButton GetOL() {
        return this._rOL;
    }

    public RadioButton GetBST() {
        return this._rBST;
    }

    public RadioButton GetEBST() {
        return this._rEBST;
    }

    public RadioButton GetSPT() {
        return this._rSPT;
    }

    public RadioButton GetLPT() {
        return this._rLPT;
    }

    public RadioButton GetWSPT() {
        return this._rWSPT;
    }

    public RadioButton GetFCFS() {
        return this._rFCFS;
    }

    public RadioButton GetBF() {
        return this._rbf;
    }

    public RadioButton GetNBF() {
        return this._rnbf;
    }

    // Management of the Schedule data
    @FXML
    public void Exec_Schedule() throws Exception {
        CleanDiagram();

        if (GetInput().toString().isBlank())
            throw new NullPointerException("Exec_Schedule() : Input Path is not nullable");
        if (GetOutput().toString().isBlank())
            throw new NullPointerException("Exec_Schedule() : Output Path is not nullable");

        if (GetOL().isSelected()) {
            if (GetSPT().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 0, 0, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 0, 0, 0);
                else
                    throw new Exception("Exec_Schedule() OLSPT : Selection out of range.");}
            else if (GetLPT().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 0, 1, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 0, 1, 0);
                else
                    throw new Exception("Exec_Schedule() OLLPT : Selection out of range.");
            }
            else if (GetWSPT().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 0, 2, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 0, 2, 0);
                else
                    throw new Exception("Exec_Schedule() OLWSPT : Selection out of range.");
            }
            else if (GetFCFS().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 0, 3, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 0, 3, 0);
                else
                    throw new Exception("Exec_Schedule() OLFCFS : Selection out of range.");
            }
            else
                throw new Exception("Exec_Schedule() OL : Selection out of range.");
        }
        else if (GetBST().isSelected()) {
            if (GetSPT().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 1, 0, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 1, 0, 0);
                else
                    throw new Exception("Exec_Schedule() BSTSPT : Selection out of range.");}
            else if (GetLPT().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 1, 1, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 1, 1, 0);
                else
                    throw new Exception("Exec_Schedule() BSTLPT : Selection out of range.");
            }
            else if (GetWSPT().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 1, 2, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 1, 2, 0);
                else
                    throw new Exception("Exec_Schedule() BSTWSPT : Selection out of range.");
            }
            else if (GetFCFS().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 1, 3, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 1, 3, 0);
                else
                    throw new Exception("Exec_Schedule() BSTFCFS : Selection out of range.");
            }
            else
                throw new Exception("Exec_Schedule() BST : Selection out of range.");
        }
        else if (GetEBST().isSelected()) {
            if (GetSPT().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 2, 0, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 2, 0, 0);
                else
                    throw new Exception("Exec_Schedule() EBSTSPT : Selection out of range.");
            }
            else if (GetLPT().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 2, 1, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 2, 1, 0);
                else
                    throw new Exception("Exec_Schedule() EBSTLPT : Selection out of range.");
            }
            else if (GetWSPT().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 2, 2, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 2, 2, 0);
                else
                    throw new Exception("Exec_Schedule() EBSTWSPT : Selection out of range.");
            }
            else if (GetFCFS().isSelected()) {
                if (GetBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 2, 3, 1);
                else if (GetNBF().isSelected())
                    SetSchedule(GetInput().getText(), GetOutput().getText(), 2, 3, 0);
                else
                    throw new Exception("Exec_Schedule() EBSTFCFS : Selection out of range.");
            }
            else
                throw new Exception("Exec_Schedule() EBST : Selection out of range.");
        }
        else
            throw new Exception("Exec_Schedule() ALL : Selection out of range.");

        SetDiagramAndSum();

    }

    // Diagram
    @FXML
    public void SetDiagramAndSum() throws Exception {
        if (!GetOutput().getText().isBlank()) {
            // Constant
            final int DEFAULT_MARGIN = 30;

            // Variable
            String path_output = GetOutput().getText();

            long makespan = 0, wjcj = 0, wjtj = 0, wjfj = 0;
            int r = 0, g = 0, b = 0;

            int nbr = 0; // Nb of rectangle

            System.out.println("Make diagram, path : " + path_output);

            try {

                File file = new File(path_output);

                Scanner reader = new Scanner(file);

                System.out.println("SetDiagramAndSum <Status> : Entering Loop.");

                while (reader.hasNextLine()) {
                    String [] data = reader.nextLine().split(" ");

                    // Setup variable with data
                    String id = data[0];
                    long start = StrToLong(data[5]);
                    long time = StrToLong(data[1]);
                    long weight = StrToLong(data[4]);
                    // Variable for sum
                    long end = start + time; // Cj
                    long completion = Long.max(0, end - StrToLong(data[3])); // Tj
                    long response = end - StrToLong(data[2]); // Fj

                    // Calculate sum
                    makespan = Long.max(makespan, end);
                    wjcj += end * weight;
                    wjtj += completion * weight;
                    wjfj += response * weight;

                    do {
                        r = ThreadLocalRandom.current().nextInt(0, 256);
                        g = ThreadLocalRandom.current().nextInt(0, 256);
                        b = ThreadLocalRandom.current().nextInt(0, 256);
                    } while (r == 255 && g == 255 && b == 255);

                    // Set StackPane to contain Button and Rectangle
                    StackPane stack = new StackPane();
                    // Setup Rectangle
                    Rectangle rec = new Rectangle(DEFAULT_MARGIN * time, DEFAULT_MARGIN);
                    rec.setFill(Color.rgb(r, g, b, 1));

                    // Setup Button for Rectangle:ID
                    Button btn = new Button(id);
                    btn.setStyle("-fx-text-fill: red;");
                    btn.setOnAction(new EventHandler<ActionEvent>() {
                        @Override
                        public void handle(ActionEvent actionEvent) {
                            VBox root = new VBox();
                            root.getChildren().addAll(
                                    new Label("ID : " + id),
                                    new Label("Date de Commencement : " + LongToStr(start)),
                                    new Label("Processing Time : " + LongToStr(time)),
                                    new Label("Date de fin : " + LongToStr(end)),
                                    new Label("Poids : " + LongToStr(weight)),
                                    new Label("Tj : " + LongToStr(completion)),
                                    new Label("Fj : " + LongToStr(response))
                            );
                            Stage stage = new Stage();
                            stage.setTitle("Tache ID : " + id);
                            stage.setScene(new Scene(root, 300, 150));
                            stage.show();
                        }
                    });

                    // Add To StackPane
                    stack.getChildren().addAll(rec, btn);
                    stack.setLayoutX(DEFAULT_MARGIN * start);
                    stack.setLayoutY(DEFAULT_MARGIN * (nbr + 1));
                    nbr++;

                    // Add to diagram
                    GetDiagram().getChildren().add(stack);

                }
                System.out.println("Out of Diagram Loop");

                // Setup Column
                GetViewContent().getChildren().clear();
                if (nbr < 200) {
                    for (int i = 1; i <= makespan + 1; i++) {
                        Label label = new Label(IntToStr(i));
                        label.setMaxWidth(DEFAULT_MARGIN);
                        label.setMinWidth(DEFAULT_MARGIN);
                        label.setPrefWidth(DEFAULT_MARGIN);
                        label.setMaxHeight(DEFAULT_MARGIN);
                        label.setMinHeight(DEFAULT_MARGIN);
                        label.setPrefHeight(DEFAULT_MARGIN);

                        label.setAlignment(Pos.CENTER);
                        label.getStyleClass().add("column");

                        GetViewContent().getChildren().add(label);
                    }
                }
                else {

                    Label label = new Label("L'axe est trop grande pour être affiché. Cependant vous pouvez toujours voir les données.");
                    GetViewContent().getChildren().add(label);
                }


                // Change Label for Sum
                SetMakespan(makespan);
                SetWjCj(wjcj);
                SetWjTj(wjtj);
                SetWjFj(wjfj);

            } catch (FileNotFoundException e) {
                System.out.println("SetDiagramAnSum <FileNotFoundException> : File is not found.");
                e.printStackTrace();
            }
        }
        else {
            throw new Exception("SetDiagramAndSum <variable> : Output is undefined");
        }
    }

    private void CleanDiagram() {
        GetDiagram().getChildren().clear();
    }

    private long StrToLong(String str) throws Exception {
        if (str.isEmpty())
            throw new NullPointerException("StrToLong : str is not nullable.");
        if (str.contains("-"))
            throw new Exception("StrToLong : Conversion only available for positive value.");
        return Long.parseLong(str);
    }

    private String LongToStr(long i) {
        return Long.toString(i);
    }

    private String IntToStr(int i) {
        return Integer.toString(i);
    }

}
