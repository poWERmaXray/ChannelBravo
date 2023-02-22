package ray.channelBravo.bean;

import com.alibaba.druid.sql.visitor.functions.Char;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.util.Date;
import java.util.List;

@Data
public class BravoUser implements Serializable {
    private static final long serialVersionUID = 7016709135039922768L;
    private Long bravoId;
    private String bravoGender;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private Date bravoBirthday;
    private String bravoName;
    private Integer bravoAge;
    private List<String> bravoTags;
    private String accountId;
    private String password;

    private BravoUser() {}
    public static BravoUser of(String gender, Date birthday, String name, Integer age, String account, String password){
        BravoUser bravoUser = new BravoUser();
        bravoUser.bravoGender = gender;
        bravoUser.bravoBirthday = birthday;
        bravoUser.bravoName = name;
        bravoUser.bravoAge = age;
        bravoUser.accountId = account;
        bravoUser.password = password;
        return bravoUser;
    }

    public static BravoUser of() {
        return new BravoUser();
    }
}
