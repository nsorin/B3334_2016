package metier.modele;

import java.util.Date;
import javax.annotation.Generated;
import javax.persistence.metamodel.SingularAttribute;
import javax.persistence.metamodel.StaticMetamodel;
import metier.modele.Activite;
import metier.modele.Adherent;
import metier.modele.Evenement;

@Generated(value="EclipseLink-2.5.2.v20140319-rNA", date="2016-03-15T14:19:44")
@StaticMetamodel(Demande.class)
public class Demande_ { 

    public static volatile SingularAttribute<Demande, Integer> id;
    public static volatile SingularAttribute<Demande, Activite> activite;
    public static volatile SingularAttribute<Demande, Evenement> evenement;
    public static volatile SingularAttribute<Demande, Date> date;
    public static volatile SingularAttribute<Demande, Adherent> adherent;

}