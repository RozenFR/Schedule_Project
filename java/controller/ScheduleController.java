package controller;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.FileChooser;
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
    @FXML private TableView _Table;

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

    private void SetMakespan(int makespan) throws Exception {
        if (makespan < 0)
            throw new Exception("SetMakespan <variable> : makespan can't be negative.");
        GetMakespan().setText(IntToStr(makespan));
    }

    private void SetWjCj(int wjcj) throws Exception {
        if (wjcj < 0)
            throw new Exception("SetWjCj <variable> : wjcj can't be negative.");
        GetWjCj().setText(IntToStr(wjcj));
    }

    private void SetWjTj(int wjtj) throws Exception {
        if (wjtj < 0)
            throw new Exception("SetWjTj <variable> : wjtj can't be negative.");
        GetWjTj().setText(IntToStr(wjtj));
    }

    private void SetWjFj(int wjfj) throws Exception {
        if (wjfj < 0)
            throw new Exception("SetWjFj <variable> : wjfj can't be negative.");
        GetWjFj().setText(IntToStr(wjfj));
    }

    // Getter
    public AnchorPane GetDiagram() {
        return this._diagram;
    }

    public TableView GetTable() {
        return this._Table;
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
                    SetSchedule(GetInput().toString(), GetOutput().getText(), 0, 1, 0);
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

            int makespan = 0, wjcj = 0, wjtj = 0, wjfj = 0;
            int r = 0, g = 0, b= 0;

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
                    int start = StrToInt(data[5]);
                    int time = StrToInt(data[1]);
                    int weight = StrToInt(data[4]);
                    // Variable for sum
                    int end = start + time; // Cj
                    int completion = Integer.max(0, end - StrToInt(data[3])); // Tj
                    int response = end - StrToInt(data[2]); // Fj

                    // Calculate sum
                    makespan = Integer.max(makespan, end);
                    wjcj += end * weight;
                    wjtj += completion * weight;
                    wjfj += response * weight;

                    do {
                        r = ThreadLocalRandom.current().nextInt(0, 256);
                        g = ThreadLocalRandom.current().nextInt(0, 256);
                        b = ThreadLocalRandom.current().nextInt(0, 256);
                    } while (r == 255 && g == 255 && b == 255);

                    // Setup Rectangle
                    System.out.println("Rectangle Input ID Number : " + id);

                    StackPane stack = new StackPane();

                    Text txt = new Text(data[0]);
                    txt.setFill(Color.WHITE);
                    txt.setFont(Font.font(14));
                    Rectangle rec = new Rectangle(DEFAULT_MARGIN * time + DEFAULT_MARGIN, DEFAULT_MARGIN);
                    rec.setFill(Color.rgb(r, g, b, 1));
                    stack.getChildren().addAll(rec, txt);
                    stack.setLayoutX(DEFAULT_MARGIN * start);
                    stack.setLayoutY(DEFAULT_MARGIN * nbr + 25);
                    nbr++;

                    // Add to diagram
                    GetDiagram().getChildren().add(stack);

                }

                // Setup Column
                GetTable().getColumns().clear();
                for (int i = 0; i != makespan + 1; i++) {
                    TableColumn column = new TableColumn(IntToStr(i));
                    column.setMinWidth(DEFAULT_MARGIN);
                    column.setMaxWidth(DEFAULT_MARGIN);
                    column.setPrefWidth(DEFAULT_MARGIN);

                    GetTable().getColumns().add(column);
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

    private int StrToInt(String str) throws Exception {
        if (str.isEmpty())
            throw new NullPointerException("StrToInt : str is not nullable.");
        if (str.contains("-"))
            throw new Exception("StrToInt : Conversion only available for positive value.");
        return Integer.parseInt(str);
    }

    private String IntToStr(int i) {
        return Integer.toString(i);
    }

}
