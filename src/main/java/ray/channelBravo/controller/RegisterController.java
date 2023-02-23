package ray.channelBravo.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.view.RedirectView;
import ray.channelBravo.bean.BravoUser;
import ray.channelBravo.service.BravoUserService;

@RestController
@RequestMapping("/Register")
public class RegisterController {

    @Autowired
    private BravoUserService bravoUserService;

    @PostMapping("/SignUp")
    public RedirectView submitSignUpForm(BravoUser user) {
        Long result = bravoUserService.singUp(user);
        if (0 == result){
            return new RedirectView("Welcome");
        }
        return null;
    }
}
