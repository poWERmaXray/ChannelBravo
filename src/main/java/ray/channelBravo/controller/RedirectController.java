package ray.channelBravo.controller;

import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class RedirectController {

    @GetMapping("/SignUp")
    public String showSignUpForm() {
        return "Registration";
    }

    @GetMapping("")
    public String welcome() {
        return "Welcome";
    }

    @GetMapping("/Unreal")
    public ResponseEntity<String> unrealConnection() {
        return ResponseEntity.ok("OK");
    }
}
