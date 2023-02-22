package ray.channelBravo.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import ray.channelBravo.bean.BravoUser;
import ray.channelBravo.service.BravoUserService;

@RestController
@RequestMapping("/Register")
public class RegisterController {

    @Autowired
    private BravoUserService bravoUserService;

    @PostMapping("/SingUp")
    public ResponseEntity<String> registerNewUser(BravoUser user){
        Long insertedId = bravoUserService.singUp(user);
        return ResponseEntity.ok(insertedId.toString());
    }
}
